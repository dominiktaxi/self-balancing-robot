#include "pcnt-controller.h"
#include "driver/gpio.h"
PcntController::PcntController(uint8_t pin) : _pin(pin), _pcnt_unit(nullptr), _pcnt_channel(nullptr)
{
    pcnt_unit_config_t unit_config = {};

        unit_config.low_limit = -30000;
        unit_config.high_limit = 30000;
        unit_config.flags.accum_count = 1;
    
    ESP_ERROR_CHECK(pcnt_new_unit(&unit_config, &_pcnt_unit));
    ESP_ERROR_CHECK(pcnt_unit_add_watch_point(_pcnt_unit, 30000));
    ESP_ERROR_CHECK(pcnt_unit_add_watch_point(_pcnt_unit, -30000));

    pcnt_chan_config_t channel_config = {};
    channel_config.edge_gpio_num = _pin;
    channel_config.level_gpio_num = -1;

    ESP_ERROR_CHECK(
        pcnt_new_channel(
            _pcnt_unit,
            &channel_config,
            &_pcnt_channel
        )
    );

    // Rising edge: increment
    // Falling edge: do nothing
    ESP_ERROR_CHECK(
        pcnt_channel_set_edge_action(
            _pcnt_channel,
            PCNT_CHANNEL_EDGE_ACTION_INCREASE,
            PCNT_CHANNEL_EDGE_ACTION_HOLD
        )
    );

    ESP_ERROR_CHECK(pcnt_unit_enable(_pcnt_unit));
    ESP_ERROR_CHECK(pcnt_unit_clear_count(_pcnt_unit));
    ESP_ERROR_CHECK(pcnt_unit_start(_pcnt_unit));
    ESP_ERROR_CHECK(gpio_set_pull_mode(static_cast<gpio_num_t>(_pin), GPIO_PULLDOWN_ONLY));
}


int PcntController::get_pulses() const
{
    int pulse_count = 0;

    ESP_ERROR_CHECK( pcnt_unit_get_count(_pcnt_unit, &pulse_count) );
   
    return pulse_count;
}

void PcntController::clear_pulses()
{
    ESP_ERROR_CHECK(pcnt_unit_clear_count(_pcnt_unit));
}