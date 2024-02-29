// Code for the igniter task

#include <stdio.h>

#include "esp_log.h"
#include "esp_now_api.h"
#include "esp_timer.h"
#include "flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "i2c.h"
#include "sdcard.h"
#include "spi.h"
#include "driver/gpio.h"
#include "w25q64.h"
#include "console.h"
#include "flash_task.h"
#include "sd_task.h"
#include "state_machine_wrapper.h"
#include "init_task.h"
#include "lora_hw_config.h"
#include "lora_task.h"
#include <inttypes.h>
#include "esp_sntp.h"
#include "freertos/timers.h"
#include "esp_now_config.h"
#include "lora.h"

#define LORA_RST GPIO_NUM_18
#define LORA_CS GPIO_NUM_17
#define LORA_MISO GPIO_NUM_22
#define LORA_MOSI GPIO_NUM_23
#define LORA_SCK GPIO_NUM_19
#define LORA_D0 GPIO_NUM_16

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
* checked regs
*/
#define REG_RX_NB_BYTES 0x1d

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

typedef enum
{
    IGNITE = 0x01;
    CHECK_COUNTDOWN = 0x02;
} igniter_state_t;

char** parse_gs_info(char* gs_info);
void check_states_and_ignition(void* param);
void connection_with_ground_station(void* param);
void ignite_rocket(int delay_ms);
void lora_initialization(void);
void handle_received_packet(uint8_t* buffer, size_t rx_size);
static void temp_on_error(ENA_ERROR error);
static bool init_esp_now(void);

void app_main(void)
{
    // Create the tasks
    xTaskCreate(check_states_and_ignition, "CheckStatesAndIgnitionTask", IGN_STACK_SIZE, NULL, IGN_PRIORITY, NULL);
    xTaskCreate(connection_with_ground_station, "ConnectionWithGroundStationTask", CON_STACK_SIZE, NULL, CON_PRIORITY, NULL);

    //TODO: Add a condition to check if the lipo battery is connected
    {
        //TODO: Add a condition to check if the igniters are connected
        {
            //TODO: Add a condition to check if the igniters are armed
            {
                lora_initialization();
            }
        }
    }
}

char** parse_gs_info(char* gs_info, size_t rx_size)
{
    char* token;
    char* parsed_info[rx_size];
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

void ignite_rocket(int delay_ms)
{
    vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    // TODO: if any message from gs starting with "ign" is received, then abort ignition
    // TODO: set level on ignition pin
}

void lora_initialization(void)
{
    spi_init(VSPI_HOST, LORA_MOSI, LORA_MISO, LORA_SCK);
    lora_hw_spi_add_device(VSPI_HOST);
    lora_hw_set_gpio();
    lora_struct_t lora = 
    {
        ._spi_transmit = lora_hw_spi_transmit,
        ._delay = lora_hw_delay,
        ._gpio_set_level = lora_hw_gpio_set_level,
        .log = lora_hw_log,
        .rst_gpio_num = LORA_RST,
        .cs_gpio_num = LORA_CS,
        .d0_gpio_num = LORA_D0,
        .implicit_header = 0,
        .frequency = 0
    };
    init_esp_now();
    lora_init(&lora);
    lora_set_frequency(&lora, 915e6);
    lora_set_bandwidth(&lora, LORA_BW_868_MHz); //change later setting bandwith function to handle this value
    lora_explicit_header_mode(&lora);
    lora_enable_crc(&lora);
    lora_set_receive_mode(&lora);

    uint8_t buffer[255] = {0};
    size_t rx_size;

    while (1) 
    {
        if (lora_received(&lora) == LORA_OK) 
        {
            // TODO: add checking crc errors?
            rx_size = lora_receive_packet(&lora, buffer, sizeof(buffer));
            buffer[rx_size] = '\0';
            handle_received_packet(buffer, rx_size);
            vTaskDelay(pdMS_TO_TICKS(100));
        }
        lora_set_receive_mode(&lora);
    }

    vTaskDelay(pdMS_TO_TICKS(10));
}

void handle_received_packet(uint8_t* buffer, size_t rx_size)
{
        char** parsed_info = parse_gs_info(buffer, rx_size);
        bool start_countdown = false;
        bool check_countdown_length = false;
        int countdown_length;

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
                            check_countdown_length = false;
                            break;
                        }
                        
                        start_countdown = true;
                        sscanf(parsed_info[2], "%d", &countdown_length);
                        ignite_rocket(countdown_length);
                    }
                    break;
                default:
                    //handle this message by sending it to the communication task
                    check_countdown_length = false;
                    break;
            }
        }

        free(parsed_info);
}

static void temp_on_error(ENA_ERROR error) 
{
    ESP_LOGE(TAG, "ESP NOW ERROR %d", error);
}

static bool init_esp_now(void) 
{
    esp_err_t status = ESP_OK;
    uint8_t mac_address[] = MCB_MAC;
    ENA_config_t cfg = 
    {
      .stack_depth = 8000,
      .priority = 3,
      .core_id = APP_CPU_NUM,
    };
    status |= ENA_init(mac_address);
    // status |= ENA_register_device(&esp_now_broadcast);
    // status |= ENA_register_device(&esp_now_pitot);
    status |= ENA_register_error_handler(temp_on_error);
    status |= ENA_run(&cfg);

    return status == ESP_OK ? true : false;
}
