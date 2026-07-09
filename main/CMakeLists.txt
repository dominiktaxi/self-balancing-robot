idf_component_register(SRCS "timer.c" "main.c"
                    INCLUDE_DIRS "."
                    REQUIRES mpu6050 esp_driver_ledc
                    )
