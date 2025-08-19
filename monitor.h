#pragma once
#include <stdlib.h>
#include <string>

void Alert(const std::string& message);
int isinrange(float value, float min, float max);
int istempok(float temperature);
int ispulseok(float pulseRate);
int isspo2ok(float spo2);
int isbloodsugarok(float bloodsugar);
int isbloodpressureok(float bloodpressure);
int isrespirationok(float respiration);
int vitalsOk(float temperature, float pulseRate, float spo2, float respiration, float bloodpressure, float bloodsugar);










