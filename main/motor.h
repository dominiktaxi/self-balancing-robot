#pragma once
#include <inttypes.h>
#include "pwm-controller.h"
class Motor
{
    public:
    
    Motor(uint8_t, uint8_t, uint8_t, uint8_t);
    static void ledc_init();
    void switch_dir();
    void set_pwm(uint8_t pwm);
    uint8_t pwm_pin();
    private:
    PwmController _pwmController;
    bool forward;
    uint8_t _dir_pin;
    uint8_t _pwm_pin;
    uint8_t _encoder_A_pin;
    uint8_t _encoder_B_pin;

};