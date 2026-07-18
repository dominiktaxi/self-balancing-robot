#include "pcnt-controller.h"

PcntController::PcntController(uint8_t pin) : _pin(pin), _pcnt_unit(nullptr), _pcnt_channel(nullptr)
{
    pcnt_unit_config_t unit_config = 
    {
        .low_limit = -30000,
        .high_limit = 30000
    };
    ESP_ERROR_CHECK(pcnt_new_unit(&unit_config, &_pcnt_unit));

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

}


int PcntController::get_pulses()
{
    int pulse_count = 0;

    ESP_ERROR_CHECK( pcnt_unit_get_count(_pcnt_unit, &pulse_count) );
    ESP_ERROR_CHECK(pcnt_unit_clear_count(_pcnt_unit));
    return pulse_count;
}

