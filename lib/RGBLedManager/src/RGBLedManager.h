#ifndef RGBLEDMANAGER_H
#define RGBLEDMANAGER_H

#include <Arduino.h>

class RGBLedManager
{
public:
    void hexToRGB(const String& hex);
    void hueToRGB(uint8_t hue, uint8_t brightness);

    void setRGB(uint8_t r, uint8_t g, uint8_t b);
    void setColorWithParticles(uint16_t particles);

    uint8_t ledR = 12;  
    uint8_t ledG = 13;
    uint8_t ledB = 14; 

    uint32_t R, G, B; 

    String hexColors[11] = { "00ccff", "0099cc", "006699", "ffff00", "ffcc00", "ff9933", "ff6666", "ff0000", "cc0000", "990000", "990000"};

private:
    uint8_t ledArray[3] = {1, 2, 3}; 	
    const boolean invert = false; 		

    uint8_t color = 0;         
             
    uint8_t brightness = 255;  

    void loop();
};

#endif