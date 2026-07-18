#pragma once
#include <inttypes.h>
#include "pwm-controller.h"
#include "pcnt-controller.h"
class Motor
{
    public:
    
    Motor(uint8_t, uint8_t, uint8_t, uint8_t, PwmController::CHANNEL);
    void switch_dir();
    void set_pwm(uint8_t pwm);
    uint8_t pwm_pin();
    private:
    PwmController _pwmController;
    bool _forward;
    uint8_t _dir_pin;
    uint8_t _pwm_pin;
    uint8_t _encoder_A_pin;
    uint8_t _encoder_B_pin;
    PwmController::CHANNEL _channel;
    //PcntController _pcntController;
};