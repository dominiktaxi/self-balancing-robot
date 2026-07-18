#include "motor.h"
#include "driver/gpio.h"
#include "gpio-controller.h"

Motor::Motor(uint8_t dir_pin, uint8_t pwm_pin, uint8_t encoder_A_pin, uint8_t encoder_B_pin, PwmController::CHANNEL channel) : 
_forward(true), _dir_pin(dir_pin), _pwm_pin(pwm_pin), _encoder_A_pin(encoder_A_pin), _encoder_B_pin(encoder_B_pin), 
_channel(channel) //_pcntController(_encoder_A_pin)
{
    GpioController::setDirection(_dir_pin, GpioController::DIRECTION::OUTPUT);
    GpioController::setDirection(_pwm_pin, GpioController::DIRECTION::OUTPUT);
    GpioController::setDirection(_encoder_A_pin, GpioController::DIRECTION::INPUT);
    GpioController::setDirection(_encoder_B_pin, GpioController::DIRECTION::INPUT);
    GpioController::state(_dir_pin, GpioController::STATE::HIGH);
     _pwmController.pwm_pin_init(_pwm_pin, _channel);
}



void Motor::switch_dir()
{
    _forward = !_forward;
    if(_forward)
    {
        GpioController::state(_dir_pin, GpioController::STATE::HIGH);
        printf("HIGH\n");
    }
    else
    {
        printf("LOW\n");
        GpioController::state(_dir_pin, GpioController::STATE::LOW);
    }
    
}

void Motor::set_pwm(uint8_t pwm_percentage)
{
    _pwmController.pwm_set(pwm_percentage, _channel);
}

uint8_t Motor::pwm_pin()
{
    return _pwm_pin;
}