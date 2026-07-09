#ifndef TIMER_H
#define TIMER_H
#include "driver/ledc.h"
class PwmController
{
    public:
    enum class CHANNEL
    {
        CHANNEL0,
        CHANNEL1
    };
    static void ledc_init(void);
    void pwm_pin_init(uint8_t, PwmController::CHANNEL);
    void pwm_set(float);
    private:

};

#endif