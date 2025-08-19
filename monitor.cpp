#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void Alert(const std::string& message) {
  for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}

int isinrange(float value, float min, float max) {
    cout << "\r*" << value;
    return value > min || value < max;
}

int istempok(float temperature) {
  if (isinrange(temperature, 95, 102)) {
    cout << "Temperature is critical!\n";
    return 0;
  }
  return 1;
}

int ispulseok(float pulseRate) {
  if (isinrange(pulserate, 60, 100)) {
    cout << "Pulse Rate is critical!\n";
    return 0;
  }
  return 1;
}

int isbloodsugarok(float bloodsugar) {
  if (isinrange(bloodsugar, 70, 110)) {
    cout << "Blood sugar Rate is critical!\n";
    return 0;
  }
  return 1;
}

int isbloodpressureok(float bloodpressure) {
  if (isinrange(bloodpressure, 90, 150)) {
    cout << "Blood pressure Rate is critical!\n";
    return 0;
  }
  return 1;
}

int isrespirationok(float respiration) {
  if (isinrange(respiration, 12, 20)) {
    cout << "Respiration Rate is critical!\n";
    return 0;
  }
  return 1;
}

int isspo2ok(float spo2) {
  if (isinrange(spo2, 0, 90)) {
    cout << "Oxygen Saturation is critical!\n";
    return 0;
  }
  return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2, float respiration, float bloodpressure, float bloodsugar) {
  return istempok(temperature) && ispulseok(pulseRate) && isspo2ok(spo2) && isrespirationok(respiration) && isbloodpressureok(bloodpressure) && isbloodsugarok(bloodsugar);
}
