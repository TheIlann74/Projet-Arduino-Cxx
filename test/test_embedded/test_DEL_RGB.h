#include "RGBLedManager.h"
#include <Arduino.h>

class test_DEL_RGB {
public:
    void runTests();
    RGBLedManager rgbLedManager;

    void setUp() {
        //Serial.begin(9600);
    }

    void tearDown() {
        //delete testInstance;
    }

    void test_HexToRGB_with_blue_hex() {
        rgbLedManager.hexToRGB("00ccff");

        TEST_ASSERT_EQUAL_UINT8(0, rgbLedManager.R);
        TEST_ASSERT_EQUAL_UINT8(204, rgbLedManager.G);
        TEST_ASSERT_EQUAL_UINT8(255, rgbLedManager.B);
    }

    void test_set_RGB_for_led() {
        rgbLedManager.setRGB(255, 0, 0);

        TEST_ASSERT_EQUAL_UINT8(255, rgbLedManager.R);
        TEST_ASSERT_EQUAL_UINT8(0, rgbLedManager.G);
        TEST_ASSERT_EQUAL_UINT8(0, rgbLedManager.B);
    }

    void test_set_color_with_90_particles() {
        rgbLedManager.setColorWithParticles(90);

        TEST_ASSERT_EQUAL_UINT8(204, rgbLedManager.R);
        TEST_ASSERT_EQUAL_UINT8(0, rgbLedManager.G);
        TEST_ASSERT_EQUAL_UINT8(0, rgbLedManager.B);
    }

    void test_set_color_with_1000_particles() {
        rgbLedManager.setColorWithParticles(1000);

        TEST_ASSERT_EQUAL_UINT8(153, rgbLedManager.R);
        TEST_ASSERT_EQUAL_UINT8(0, rgbLedManager.G);
        TEST_ASSERT_EQUAL_UINT8(0, rgbLedManager.B);
    }

    void test_set_color_with_0_particle() {
        rgbLedManager.setColorWithParticles(0);

        TEST_ASSERT_EQUAL_UINT8(0, rgbLedManager.R);
        TEST_ASSERT_EQUAL_UINT8(204, rgbLedManager.G);
        TEST_ASSERT_EQUAL_UINT8(255, rgbLedManager.B);
    }

    void test_DEL_color_changes_when_pm25_value_increment_from_0_to_300( ) {
        ledcAttachPin(rgbLedManager.ledR, 1);
        ledcAttachPin(rgbLedManager.ledG, 2);
        ledcAttachPin(rgbLedManager.ledB, 3);

        ledcSetup(1, 12000, 8);
        ledcSetup(2, 12000, 8);
        ledcSetup(3, 12000, 8);

        for (int i = 0; i <= 300; i += 10)
        {
            Serial.println("Valeur de la led : " +  i);
            rgbLedManager.setColorWithParticles(i);
            delay(500);
        }
    }

private:

};