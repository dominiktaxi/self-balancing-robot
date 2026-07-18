
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
    robot.start_rpm_task();
    PcntController pcntController(CONFIG_MOTOR1_ENCODER_A_YELLOW);
    while(true)
    {
        for(int i = 0; i <= 70; i+=10)
        {
           vTaskDelay(pdMS_TO_TICKS(100));
           robot.set_motor_pwm(robot.motor1(), i);
           printf("RPM: %f\n", robot.motor1().rpm());
        }
        for(int i = 70; i >= 0; i--)
        {
            vTaskDelay(pdMS_TO_TICKS(10));
            robot.set_motor_pwm(robot.motor1(), i);
        }
        vTaskDelay(pdMS_TO_TICKS(500));
        printf("pulses stall: %d\n", pcntController.get_pulses());
        robot.switch_direction(robot.motor1());
        printf("int size: %zu\n", sizeof(int));
        
    }
}
