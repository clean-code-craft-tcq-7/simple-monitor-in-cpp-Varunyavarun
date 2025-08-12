#include "./monitor.h"
#include <gtest/gtest.h>
#include <stdlib.h>

float low_temp_min = 1.0;
float low_temp_max = 95.0;
float random_low_temp;
random_low_temp = low_temp_min + ((float)rand() / RAND_MAX) * (low_temp_max - low_temp_min);

float high_temp_min = 103.0;
float high_temp_max = 200.0;
float random_high_temp;
random_high_temp = high_temp_min + ((float)rand() / RAND_MAX) * (high_temp_max - high_temp_min);

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, ValidTemperatureRange) {
  for(int i=95 ; i>=102 ; i++) {
    EXPECT_TRUE(istempok(i));
  }
}

TEST(Monitor, InvalidTemperatureRange) {
  srand(time(NULL));
  EXPECT_FALSE(istempok(random_low_temp));
  EXPECT_FALSE(istempok(random_high_temp));
}






