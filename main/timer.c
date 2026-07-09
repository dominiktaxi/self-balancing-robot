#include "timer.h"

#define PWM_GPIO        5
#define PWM_FREQUENCY   20000
#define PWM_RESOLUTION  LEDC_TIMER_10_BIT
#define LEDC_SPEED_MODE LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL LEDC_CHANNEL_0

void pwm_init(void)
{
      ledc_timer_config_t timer = 
        {
        .speed_mode = LEDC_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .duty_resolution = PWM_RESOLUTION,
        .freq_hz = PWM_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK
        };

    ESP_ERROR_CHECK(ledc_timer_config(&timer));
    
    ledc_channel_config_t channel = {
        .gpio_num = PWM_GPIO,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = LEDC_CHANNEL,
        .timer_sel = LEDC_TIMER_0,
        .duty = 0,
        .hpoint = 0
    };

    ESP_ERROR_CHECK (ledc_channel_config(&channel));
}

void pwm_set(float pwm_duty)
{
    int resolution = (1 << PWM_RESOLUTION) - 1;
    int duty = pwm_duty * resolution;
    ESP_ERROR_CHECK(ledc_set_duty(LEDC_SPEED_MODE, LEDC_CHANNEL, duty));
    ESP_ERROR_CHECK(ledc_update_duty(LEDC_SPEED_MODE, LEDC_CHANNEL));
}