
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "imu-sensor.h"
#include "robot.h"
#include "pcnt-controller.h"

extern "C" void app_main()
{
    // static ImuSensor sensor;
    // sensor.init();
    // sensor.start_test();
    Robot robot;
    PcntController pcntController(CONFIG_MOTOR1_ENCODER_A_YELLOW);
    while(true)
    {
        for(uint8_t i = 0; i < 100; i++)
        {
           vTaskDelay(pdMS_TO_TICKS(5));
           robot.set_motor_pwm(robot.motor1(), i);
        printf("\033[2J\033[H");
        printf("pulses: %d", pcntController.get_pulses());
        }
        for(uint8_t i = 100; i > 0; i--)
        {
            vTaskDelay(pdMS_TO_TICKS(20));
            robot.set_motor_pwm(robot.motor1(), i);
        printf("\033[2J\033[H");
        printf("pulses: %d", pcntController.get_pulses());
        }
        robot.switch_direction(robot.motor1());
    }
}
