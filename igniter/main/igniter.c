#include <stdio.h>
#include <stdbool.h>

void app_main(void)
{
    bool start_countdown = false;

    //TODO: Create two tasks: one for checking states and igintion and another for connection with ground station

    //TODO: Add a condition to check if the lipo battery is connected
    {
        //TODO: Add a condition to check if the igniters are connected
        {
            //TODO: Add a condition to check if the igniters are armed
            {
                while (! start_countdown)
                {
                    //TODO: Add a switch to interpret the information incoming from the gs - if it is a start code wait for the countdown length and go to countdown, otherwise handle it with communication task
                }

                //TODO: Add a countdown to the ignition
                {
                    //TODO: Wait the specified amount of time and ignite the rocket
                }
            
            }
        }
    }
}
