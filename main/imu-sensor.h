#pragma once
#include <mpu6050.h>
#include "driver/gpio.h"

class ImuSensor
{
    public:
    ImuSensor();
    void init();
    void start_test();
    private:
    mpu6050_dev_t _dev;
    static void mpu6050_test(void *pvParameters);
};