#include "robot.h"

Robot::Robot() : _motor1(CONFIG_MOTOR1_DIR_GPIO, 
        CONFIG_MOTOR1_PWM_GPIO, 
        CONFIG_MOTOR1_ENCODER_A_YELLOW, 
        CONFIG_MOTOR1_ENCODER_B_WHITE), 

        _motor2(CONFIG_MOTOR2_DIR_GPIO, 
        CONFIG_MOTOR2_PWM_GPIO, 
        CONFIG_MOTOR2_ENCODER_A_YELLOW, 
        CONFIG_MOTOR2_ENCODER_B_WHITE)
{       
    _pwmController.pwm_pin_init(_motor1.pwm_pin(), PwmController::CHANNEL::CHANNEL0);
    _pwmController.pwm_pin_init(_motor2.pwm_pin(), PwmController::CHANNEL::CHANNEL1);     
}