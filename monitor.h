#pragma once
#include <stdlib.h>
#include <string>

void Alert(const std::string& message);
int istempok(float temperature);
int ispulseok(float pulseRate);
int isspo2ok(float spo2);
int vitalsOk(float temperature, float pulseRate, float spo2);









