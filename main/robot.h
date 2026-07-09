#pragma once
#include "motor.h"
#include "pwm-controller.h"
class Robot
{
    public:
    Robot();
    private:
    PwmController _pwmController;
    Motor _motor1;
    Motor _motor2;
};