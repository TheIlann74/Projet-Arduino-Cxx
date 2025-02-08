#include <unity.h>
#include "test_DEL_RGB.h"
#include "test_AqhiScale.h"

test_DEL_RGB testRGB;
test_AqhiScale testAqhi;

void setUp() {
    testRGB.setUp();
    testAqhi.setUp();
}

void tearDown() {
    testRGB.tearDown();
    testAqhi.tearDown();
}

void test_HexToRGB_with_blue_hex() {
    testRGB.test_HexToRGB_with_blue_hex();
}

void test_set_RGB_for_led() {
    testRGB.test_set_RGB_for_led();
}

void test_set_color_with_90_particles() {
    testRGB.test_set_color_with_90_particles();
}

void test_set_color_with_1000_particles() {
    testRGB.test_set_color_with_1000_particles();
}

void test_set_color_with_0_particle() {
    testRGB.test_set_color_with_0_particle();
}

void test_DEL_color_changes_when_pm25_value_increment_from_0_to_300() {
    testRGB.test_DEL_color_changes_when_pm25_value_increment_from_0_to_300();
}


void test_pmValue_good() {
    testAqhi.test_pmValue_good();
}

void test_pmValue_moderate() {
    testAqhi.test_pmValue_moderate();
}

void test_pmValue_bad_for_sensitive() {
    testAqhi.test_pmValue_bad_for_sensitive();
}

void test_pmValue_bad_for_health() {
    testAqhi.test_pmValue_bad_for_health();
}

void test_pmValue_very_bad() {
    testAqhi.test_pmValue_very_bad();
}

void test_pmValue_dangerous() {
    testAqhi.test_pmValue_dangerous();
}

void RUN_UNITY_TESTS() {
    UNITY_BEGIN();
    RUN_TEST(test_HexToRGB_with_blue_hex);
    RUN_TEST(test_set_RGB_for_led);
    RUN_TEST(test_set_color_with_90_particles);
    RUN_TEST(test_set_color_with_1000_particles);
    RUN_TEST(test_set_color_with_0_particle);
    RUN_TEST(test_DEL_color_changes_when_pm25_value_increment_from_0_to_300);

    RUN_TEST(test_pmValue_good);
    RUN_TEST(test_pmValue_moderate);
    RUN_TEST(test_pmValue_bad_for_sensitive);
    RUN_TEST(test_pmValue_bad_for_health);
    RUN_TEST(test_pmValue_very_bad);
    RUN_TEST(test_pmValue_dangerous);
    UNITY_END();
}

#ifdef ARDUINO

#include <Arduino.h>
void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    RUN_UNITY_TESTS();
}

void loop() {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(500);
}

#else

int main(int argc, char **argv) {
    RUN_UNITY_TESTS();
    return 0;
}

#endif