#include <gtest/gtest.h>
#include "./monitor.h"
#include <stdlib.h> 

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}

TEST(Monitor, ValidTemperatureRange) {
for(i=95 ; i>102 ; i++){
  EXPECT_TRUE(istempok(i));
}

TEST(Monitor, InvalidTemperatureRange) {
  EXPECT_FALSE(istempok(random_low_temp));
  EXPECT_FALSE(istempok(random_high_temp));
}
