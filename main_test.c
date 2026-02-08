/*
* This is the main test file for the onboarding task.
* It runs a series of tests on the validate_sensor_data function
* to ensure it meets the specified requirements.
* There is no need to modify this file.
* Created for the Space Concordia firmware onboarding task by Lucas Gentil.
*/

#include <stdio.h>
#include "status_defines.h"

// ANSI Color Codes
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RESET   "\033[0m"

int main() {
    uint8_t faults = 0;
    int tests_passed = 0;

    printf("\n" YELLOW "--- Onboarding Test ---" RESET "\n\n");

    // Test 1: Valid Data
    if (validate_sensor_data(50.0f, 0.0f, 100.0f, &faults) == STATUS_OK && faults == 0 ) {
        printf(GREEN "[PASS]" RESET " Valid Data Check\n");
        tests_passed++;
    } else { printf(RED "[FAIL]" RESET " Valid Data Check\n"); }

    // Test 2: Out of Range Data
    faults = 0;
    if (validate_sensor_data(150.0f, 0.0f, 100.0f, &faults) == STATUS_ERROR_RANGE && faults == 1 ) {
        printf(GREEN "[PASS]" RESET " Out of Range Data Check\n");
        tests_passed++;
    } else { printf(RED "[FAIL]" RESET " Out of Range Data Check\n"); }

    // Test 3: NaN Handling
    float nan_value = 0.0f / 0.0f;
    faults = 0;
    if (validate_sensor_data(nan_value, 0.0f, 100.0f, &faults) == STATUS_ERROR_INVALID && faults == 1 ) {
        printf(GREEN "[PASS]" RESET " NaN Protection Check\n");
        tests_passed++;
    } else { printf(RED "[FAIL]" RESET " NaN Protection Check\n"); }

    printf("\n-----------------------------------\n\n");

    if (tests_passed == 3) {
        printf("FINAL SCORE: " GREEN "%d/3" RESET " CONGRATULATIONS!\n", tests_passed);
    } else {
        printf("FINAL SCORE: " RED "%d/3" RESET " TRY AGAIN\n", tests_passed);
    }

    printf("\n-----------------------------------\n\n");    

    return (tests_passed == 3) ? 0 : 1;

}
