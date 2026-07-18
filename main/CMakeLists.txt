idf_component_register(SRCS "pcnt-controller.cpp" "main.cpp" "gpio-controller.cpp" "motor.cpp" "pwm-controller.cpp" "imu-sensor.cpp" "robot.cpp"
                    INCLUDE_DIRS "."
                    REQUIRES mpu6050 esp_driver_ledc esp_driver_pcnt
                    )
