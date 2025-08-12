#pragma once
#include <stdlib.h>
#include <string.h>

void Alert(const std::string& message);
int istempok(float temperature);
int ispulseok(float pulseRate);
int isspo2ok(float spo2);
int vitalsOk(float temperature, float pulseRate, float spo2);
float low_temp_min = 1.0;
float low_temp_max = 95.0;
float random_low_temp = low_temp_min + ((float)rand() / RAND_MAX) * (low_temp_max - low_temp_min);

float high_temp_min = 102.0;
float high_temp_max = 200.0;
float random_high_temp = high_temp_min + ((float)rand() / RAND_MAX) * (high_temp_max - high_temp_min);





