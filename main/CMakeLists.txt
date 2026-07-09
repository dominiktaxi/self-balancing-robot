idf_component_register(SRCS "main.cpp" "gpio-controller.cpp" "motor.cpp" "pwm-controller.cpp" "imu-sensor.cpp" "robot.cpp"
                    INCLUDE_DIRS "."
                    REQUIRES mpu6050 esp_driver_ledc
                    )
