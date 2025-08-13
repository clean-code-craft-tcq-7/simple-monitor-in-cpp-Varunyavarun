#include <gtest/gtest.h>
#include <random>
#include "./monitor.h"

std::random_device rd;
std::mt19937 gen(rd());
float low_temp_min = 1.0;
float low_temp_max = 94.0;
float high_temp_min = 103.0;
float high_temp_max = 200.0;
float low_pulse_min = 1.0;
float low_pulse_max = 89.0;
float high_pulse_min = 91.0;
float high_pulse_max = 200.0;
float low_spo2_min = 1.0;
float low_spo2_max = 89.0;
float high_spo2_min = 91.0;
float high_spo2_max = 200.0;

std::uniform_real_distribution<float> invalid_low_temp(low_temp_min, low_temp_max);
std::uniform_real_distribution<float> valid_temp(low_temp_max, high_temp_min);
std::uniform_real_distribution<float> invalid_high_temp(high_temp_min, high_temp_max);
float random_low_temp = invalid_low_temp(gen);
float random_high_temp = invalid_high_temp(gen);
float random_valid_temp = valid_temp(gen);

std::uniform_real_distribution<float> invalid_low_pulse(low_pulse_min, low_pulse_max);
std::uniform_real_distribution<float> valid_pulse(low_pulse_max, high_pulse_min);
std::uniform_real_distribution<float> invalid_high_pulse(high_pulse_min, high_pulse_max);
float random_low_pulse = invalid_low_pulse(gen);
float random_high_pulse = invalid_high_pulse(gen);
float random_valid_pulse = valid_pulse(gen);

std::uniform_real_distribution<float> valid_spo2(low_spo2_min, low_spo2_max);
std::uniform_real_distribution<float> invalid_high_spo2(high_spo2_min, high_spo2_max);
float random_high_spo2 = invalid_high_spo2(gen);
float random_valid_spo2 = valid_spo2(gen);

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, ValidTemperatureRange) {
  srand(time(NULL));
  EXPECT_TRUE(istempok(random_valid_temp));
}

TEST(Monitor, InvalidTemperatureRange) {
  srand(time(NULL));
  EXPECT_FALSE(istempok(random_low_temp));
  EXPECT_FALSE(istempok(random_high_temp));
}

TEST(Monitor, ValidPulseRange) {
  srand(time(NULL));
  EXPECT_TRUE(ispulseok(random_valid_pulse));
}

TEST(Monitor, InvalidPulseRange) {
  srand(time(NULL));
  EXPECT_FALSE(ispulseok(random_low_pulse));
  EXPECT_FALSE(ispulseok(random_high_pulse));
}

TEST(Monitor, Validspo2Range) {
  srand(time(NULL));
  EXPECT_TRUE(isspo2ok(random_valid_spo2));
}

TEST(Monitor, Invalidspo2Range) {
  srand(time(NULL));
  EXPECT_FALSE(isspo2ok(random_high_spo2));
}























