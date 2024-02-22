// Code for the igniter task

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "lora.h"
#include "driver/spi_master.h"
#include "esp_system.h"

#define LORA_RST GPIO_NUM_18
#define LORA_CS GPIO_NUM_17
#define LORA_MISO GPIO_NUM_22
#define LORA_MOSI GPIO_NUM_23
#define LORA_SCK GPIO_NUM_19

#define IGN_STACK_SIZE 2048 //TODO: Define the stack size for the igniter task
#define IGN_PRIORITY 0 //TODO: Define the priority for the igniter task

#define CON_STACK_SIZE 2048 //TODO: Define the stack size for the communication task
#define CON_PRIORITY 0 //TODO: Define the priority for the communication task

/*
 * IRQ masks
 */
#define IRQ_TX_DONE_MASK 0x08
#define IRQ_PAYLOAD_CRC_ERROR_MASK 0x20
#define IRQ_RX_DONE_MASK 0x40

#define PA_OUTPUT_RFO_PIN 0
#define PA_OUTPUT_PA_BOOST_PIN 1

#define TIMEOUT_RESET 100

/*
 * Register definitions
 */
#define REG_FIFO 0x00
#define REG_OP_MODE 0x01
#define REG_FRF_MSB 0x06
#define REG_FRF_MID 0x07
#define REG_FRF_LSB 0x08
#define REG_PA_CONFIG 0x09
#define REG_LNA 0x0c
#define REG_FIFO_ADDR_PTR 0x0d
#define REG_FIFO_TX_BASE_ADDR 0x0e
#define REG_FIFO_RX_BASE_ADDR 0x0f
#define REG_FIFO_RX_CURRENT_ADDR 0x10
#define REG_IRQ_FLAGS 0x12
#define REG_RX_NB_BYTES 0x13
#define REG_PKT_SNR_VALUE 0x19
#define REG_PKT_RSSI_VALUE 0x1a
#define REG_MODEM_CONFIG_1 0x1d
#define REG_MODEM_CONFIG_2 0x1e
#define REG_PREAMBLE_MSB 0x20
#define REG_PREAMBLE_LSB 0x21
#define REG_PAYLOAD_LENGTH 0x22
#define REG_MODEM_CONFIG_3 0x26
#define REG_RSSI_WIDEBAND 0x2c
#define REG_DETECTION_OPTIMIZE 0x31
#define REG_DETECTION_THRESHOLD 0x37
#define REG_SYNC_WORD 0x39
#define REG_DIO_MAPPING_1 0x40
#define REG_VERSION 0x42

/*
 * Transceiver modes
 */
#define MODE_LONG_RANGE_MODE 0x80
#define MODE_SLEEP 0x00
#define MODE_STDBY 0x01
#define MODE_TX 0x03
#define MODE_RX_CONTINUOUS 0x05
#define MODE_RX_SINGLE 0x06

/*
 * PA configuration
 */
#define PA_BOOST 0x80

char** parse_gs_info(char* gs_info);
void check_states_and_ignition(void* param);
void connection_with_ground_station(void* param);
esp_err_t spi_init(void);
esp_err_t add_lora_to_spi(void);
esp_err_t lora_init(void);
void lora_reset(void);
void lora_write_reg(int reg, int val);

void app_main(void)
{
    bool start_countdown = false;
    bool check_countdown_length = false;
    spi_device_handle_t lora;

    lora_init(&lora);

    // Create the tasks
    xTaskCreate(check_states_and_ignition, "CheckStatesAndIgnitionTask", IGN_STACK_SIZE, NULL, IGN_PRIORITY, NULL);
    xTaskCreate(connection_with_ground_station, "ConnectionWithGroundStationTask", CON_STACK_SIZE, NULL, CON_PRIORITY, NULL);

    //TODO: Add a condition to check if the lipo battery is connected
    {
        //TODO: Add a condition to check if the igniters are connected
        {
            //TODO: Add a condition to check if the igniters are armed
            {
                while (! start_countdown)
                {
                    printf("Enter code: "); //will be changed to a message from the ground station
                    char* gs_info = malloc(sizeof(char) * 100);
                    scanf("%s", gs_info);
                    char** parsed_info = parse_gs_info(gs_info);

                    if (strcmp(parsed_info[0], "ign") == 0)
                    {
                        int hexValue;

                        sscanf(parsed_info[1], "%x", &hexValue);

                        switch(hexValue)
                        {
                            case 0x01: //code for starting the countdown
                                check_countdown_length = true;
                                break;
                            case 0x02: //code for checking the countdown length
                                if (check_countdown_length)
                                {
                                    if (parsed_info[2] == NULL)
                                    {
                                        printf("No countdown length provided\n");
                                        check_countdown_length = false;
                                        break;
                                    }
                                    
                                    start_countdown = true;
                                    int countdown_length;
                                    sscanf(parsed_info[2], "%d", &countdown_length);
                                }
                                break;
                            default:
                                //handle this message by sending it to the communication task
                                check_countdown_length = false;
                                break;
                        }
                    }

                    free(parsed_info);
                    free(gs_info);
                }

                //TODO: Add a countdown to the ignition
                {
                    //TODO: Wait the specified amount of time and ignite the rocket
                }
            }
        }
    }
}

char** parse_gs_info(char* gs_info)
{
    char* token;
    char** parsed_info = malloc(sizeof(char*) * 3); //TODO: Allocate memory dynamically
    int i = 0;

    token = strtok(gs_info, ";");

    while (token != NULL)
    {
        parsed_info[i] = token;
        token = strtok(NULL, ";");
        i++;
    }

    return parsed_info;
}

void check_states_and_ignition(void* param)
{
    //TODO: Implement logic here

}

void connection_with_ground_station(void* param)
{
    //TODO: Implement logic here
}

esp_err_t spi_init(void)
{
    esp_err_t ret;

    spi_bus_config_t bus_config = 
    {
        .mosi_io_num = LORA_MOSI,
        .miso_io_num = LORA_MISO,
        .sclk_io_num = LORA_SCK,
        .quadwp_io_num = -1,        //check later for real value
        .quadhd_io_num = -1,        //check later for real value
        .max_transfer_sz = 0        //check later for real value
    };

    ret = spi_bus_initialize(VSPI_HOST, &bus_config, SDSPI_DEFAULT_DMA);

    return ret;
}

esp_err_t add_lora_to_spi(spi_device_handle_t* handle)
{
    esp_err_t ret;

    spi_device_interface_config_t dev_config = 
    {
        .clock_speed_hz = 10000000, // Clock out at 10 MHz; search later for real value
        .mode = 0,                  // SPI mode 0; search later for real value
        .spics_io_num = LORA_CS,    // CS pin
        .queue_size = 7,            // able to queue 7 transactions at a time; change later to correct size
    };

    ret = spi_bus_add_device(VSPI_HOST, &dev_config, handle);    

    return ret;
}

void lora_reset(void)
{
    gpio_set_level(LORA_RST, 0);
    // TODO: add delay
    gpio_set_level(LORA_RST, 1);
    // TODO: add delay
}

esp_err_t lora_init(spi_device_handle_t* handle)
{
    gpio_pad_select_gpio(LORA_RST);
    gpio_set_direction(LORA_RST, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(LORA_CS);
    gpio_set_direction(LORA_CS, GPIO_MODE_OUTPUT);

    spi_init();
    add_lora_to_spi(handle);
    lora_reset();


}

void lora_write_reg(int reg, int val)
{
    uint8_t out[2] = { 0x80 | reg, val };
    uint8_t in[2];

    spi_transaction_t transaction = 
    {
        .flags = 0,
        .length = 8 * sizeof(out),
        .tx_buffer = out,
        .rx_buffer = in  
    };

    gpio_set_level(LORA_CS, 0);
    spi_device_transmit(__spi, &transaction);
    gpio_set_level(LORA_CS, 1);
}

void lora_read_reg(int reg)
{
    uint8_t out[2] = { reg, 0xff };
    uint8_t in[2];

    spi_transaction_t transaction = 
    {
        .flags = 0,
        .length = 8 * sizeof(out),
        .tx_buffer = out,
        .rx_buffer = in  
    };

    gpio_set_level(LORA_CS, 0);
    spi_device_transmit(__spi, &transaction);
    gpio_set_level(LORA_CS, 1);
}

void lora_idle(void)
{
   lora_write_reg(REG_OP_MODE, MODE_LONG_RANGE_MODE | MODE_STDBY);
}

void lora_sleep(void)
{
    lora_write_reg(REG_OP_MODE, MODE_LONG_RANGE_MODE | MODE_SLEEP);
}

void lora_receive(void)
{
    lora_write_reg(REG_OP_MODE, MODE_LONG_RANGE_MODE | MODE_RX_CONTINUOUS);
}