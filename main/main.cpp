
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "imu-sensor.h"
#include "robot.h"

extern "C" void app_main()
{
    // static ImuSensor sensor;
    // sensor.init();
    // sensor.start_test();
    Robot robot;
    while(true)
    {
        for(uint8_t i = 0; i < 100; i++)
        {
           vTaskDelay(pdMS_TO_TICKS(20));
           robot.set_motor_pwm(robot.motor1(), i);
        }
        for(uint8_t i = 100; i > 0; i--)
        {
            vTaskDelay(pdMS_TO_TICKS(20));
            robot.set_motor_pwm(robot.motor1(), i);
        }
        robot.switch_direction(robot.motor1());
    }
}
