#pragma once
#include "driver/pulse_cnt.h"
#include "esp_err.h"
class PcntController
{
    public:
    PcntController(uint8_t);
    int get_pulses() const;
    void clear_pulses();
    private:
    uint8_t _pin;
    pcnt_unit_handle_t _pcnt_unit;
    pcnt_channel_handle_t _pcnt_channel;
};