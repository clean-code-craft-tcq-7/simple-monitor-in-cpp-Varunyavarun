#include "monitor.h"

#include <stdio.h>

#include <random>

#include <gtest/gtest.h>

std::random_device rd;
std::mt19937 gen(rd());
float low_temp_min = 1.0;
float low_temp_max = 95.0;
float high_temp_min = 103.0;
float high_temp_max = 200.0;
std::uniform_real_distribution<float> low_dist(low_temp_min, low_temp_max);
std::uniform_real_distribution<float> high_dist(high_temp_min, high_temp_max);
float random_low_temp = low_dist(gen);
float random_high_temp = high_dist(gen);

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, ValidTemperatureRange) {
  for (int i=95 ; i >= 102 ; i++) {
    EXPECT_TRUE(istempok(i));
  }
}

TEST(Monitor, InvalidTemperatureRange) {
  srand(time(NULL));
  EXPECT_FALSE(istempok(random_low_temp));
  EXPECT_FALSE(istempok(random_high_temp));
}













