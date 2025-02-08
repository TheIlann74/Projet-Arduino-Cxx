#include "PmsManager.h"
#include <Arduino.h>

class test_AqhiScale {
public:
    void runTests();
    PmsManager pmsManager;

    void setUp() {
        //Serial.begin(9600);
    }

    void tearDown() {
        //delete testInstance;
    }

    void test_pmValue_good(void) {
        String info = pmsManager.sendDisplay(10.0f);
        TEST_ASSERT_EQUAL_STRING("Air Quality: 🟢 Good", info.c_str());
    }

    void test_pmValue_moderate(void) {
        String info = pmsManager.sendDisplay(30.0f);
        TEST_ASSERT_EQUAL_STRING("Air Quality: 🟡 Moderate", info.c_str());
    }

    void test_pmValue_bad_for_sensitive(void) {
        String info = pmsManager.sendDisplay(50.0f);
        TEST_ASSERT_EQUAL_STRING("Air Quality: 🟠 Unhealthy for Sensitive Groups", info.c_str());
    }

    void test_pmValue_bad_for_health(void) {
        String info = pmsManager.sendDisplay(70.0f);
        TEST_ASSERT_EQUAL_STRING("Air Quality: 🔴 Unhealthy", info.c_str());
    }

    void test_pmValue_very_bad(void) {
        String info = pmsManager.sendDisplay(90.0f);
        TEST_ASSERT_EQUAL_STRING("Air Quality: 🟣 Very Unhealthy", info.c_str());
    }

    void test_pmValue_dangerous(void) {
        String info = pmsManager.sendDisplay(500.0f);
        TEST_ASSERT_EQUAL_STRING("Air Quality: ⚫ Hazardous", info.c_str());
    }

private:

};