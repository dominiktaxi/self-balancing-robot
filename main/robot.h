#pragma once
#include "motor.h"
#include "pwm-controller.h"
class Robot
{
    public:
    Robot();
    void set_motor_pwm(Motor, uint8_t);
    void switch_direction(Motor);
    const Motor& motor1() const;
    const Motor& motor2() const;
    private:
    PwmController _pwmController;
    Motor _motor1;
    Motor _motor2;
};