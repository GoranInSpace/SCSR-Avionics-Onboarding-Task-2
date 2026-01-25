#ifndef STATUS_DEFINES_H
#define STATUS_DEFINES_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    STATUS_OK = 0,
    STATUS_ERROR_RANGE = 1,
    STATUS_ERROR_INVALID = 2
} status_t;

status_t validate_sensor_data(float input, float min, float max, uint8_t *fault_counter);

#endif 