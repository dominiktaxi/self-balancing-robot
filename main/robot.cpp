#include "robot.h"

Robot::Robot() : _motor1(CONFIG_MOTOR1_DIR_GPIO, 
        CONFIG_MOTOR1_PWM_GPIO, 
        CONFIG_MOTOR1_ENCODER_A_YELLOW, 
        CONFIG_MOTOR1_ENCODER_B_WHITE,
        PwmController::CHANNEL::CHANNEL0), 

        _motor2(CONFIG_MOTOR2_DIR_GPIO, 
        CONFIG_MOTOR2_PWM_GPIO, 
        CONFIG_MOTOR2_ENCODER_A_YELLOW, 
        CONFIG_MOTOR2_ENCODER_B_WHITE,
        PwmController::CHANNEL::CHANNEL1)
{       
       
}

void Robot::set_motor_pwm(Motor motor, uint8_t percentage)
{
    motor.set_pwm(percentage);
}

void Robot::switch_direction(Motor motor)
{
    motor.switch_dir();
}

const Motor& Robot::motor1() const
{
    return _motor1;
}

const Motor& Robot::motor2() const
{
    return _motor2;
}