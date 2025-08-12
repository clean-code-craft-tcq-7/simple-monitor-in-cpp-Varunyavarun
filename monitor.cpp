#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void print(std :: string message) {
  for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep_for(seconds(1));
      cout << "\r *" << flush;
      sleep_for(seconds(1));
    }
}

int istempok(float temperature) {
  if (temperature > 102 || temperature < 95) {
    cout << "Temperature is critical!\n";
    print("Temperature is out of range");
    return 0;
  }
  return 1;
}

int ispulseok(float pulseRate) {
  if (pulseRate < 60 || pulseRate > 100) {
    cout << "Pulse Rate is critical!\n";
    print("Pulse Rate is out of range");
    return 0;
  }
  return 1;
}

int isspo2ok(float spo2) {
  if (spo2 < 90) {
    cout << "Oxygen Saturation is critical!\n";
    print("Oxygen Saturation is out of range");
    return 0;
  }
  return 1;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return istempok(temperature) && ispulseok(pulseRate) && isspo2ok(spo2); 
}



