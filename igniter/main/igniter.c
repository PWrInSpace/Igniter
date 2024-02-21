// Code for the igniter task

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "lora.h"

#define LORA_RS GPIO_NUM_18
#define LORA_CS GPIO_NUM_17
#define LORA_MISO GPIO_NUM_22
#define LORA_MOSI GPIO_NUM_23
#define LORA_SCK GPIO_NUM_19

#define IGN_STACK_SIZE 2048 //TODO: Define the stack size for the igniter task
#define IGN_PRIORITY 0 //TODO: Define the priority for the igniter task

#define CON_STACK_SIZE 2048 //TODO: Define the stack size for the communication task
#define CON_PRIORITY 0 //TODO: Define the priority for the communication task

char** parse_gs_info(char* gs_info);
void check_states_and_ignition(void* param);
void connection_with_ground_station(void* param);

void app_main(void)
{
    bool start_countdown = false;
    bool check_countdown_length = false;

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

