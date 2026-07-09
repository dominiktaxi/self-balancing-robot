#include "motor.h"
#include "driver/gpio.h"
#include "gpio-controller.h"

Motor::Motor(uint8_t dir_pin, uint8_t pwm_pin, uint8_t encoder_A_pin, uint8_t encoder_B_pin) : 
_dir_pin(dir_pin), _pwm_pin(pwm_pin), _encoder_A_pin(encoder_A_pin), _encoder_B_pin(encoder_B_pin)
{
    GpioController::setDirection(_dir_pin, GpioController::DIRECTION::OUTPUT);
    GpioController::setDirection(_pwm_pin, GpioController::DIRECTION::OUTPUT);
    GpioController::setDirection(_encoder_A_pin, GpioController::DIRECTION::INPUT);
    GpioController::setDirection(_encoder_B_pin, GpioController::DIRECTION::INPUT);
}

void Motor::ledc_init()
{
    PwmController::ledc_init();
}

void Motor::switch_dir()
{
    forward != forward;
    if(forward)
    {
        GpioController::state(_dir_pin, GpioController::STATE::HIGH);
    }
    else
    {
        GpioController::state(_dir_pin, GpioController::STATE::LOW);
    }
    
}

void Motor::set_pwm(uint8_t pwm_percentage)
{
    _pwmController.pwm_set(pwm_percentage);
}

uint8_t Motor::pwm_pin()
{
    return _pwm_pin;
}