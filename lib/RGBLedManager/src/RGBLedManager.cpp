#include "Arduino.h"
#include "RGBLedManager.h"

void RGBLedManager::hexToRGB(const String& hex) {
    uint32_t hexValue = strtol(hex.c_str(), nullptr, 16);

    uint8_t r = (hexValue >> 16) & 0xFF;
    uint8_t g = (hexValue >> 8) & 0xFF;
    uint8_t b = hexValue & 0xFF;

    setRGB(r, g, b);

    if (invert) {
        R = 255 - R;
        G = 255 - G;
        B = 255 - B;
    }
}

void RGBLedManager::hueToRGB(uint8_t hue, uint8_t brightness)
{
    uint16_t scaledHue = (hue * 6);
    uint8_t segment = scaledHue / 256; 
                                       
    uint16_t segmentOffset =
      scaledHue - (segment * 256);

    uint8_t complement = 0;
    uint16_t prev = (brightness * ( 255 -  segmentOffset)) / 256;
    uint16_t next = (brightness *  segmentOffset) / 256;

    if(invert)
    {
      brightness = 255 - brightness;
      complement = 255;
      prev = 255 - prev;
      next = 255 - next;
    }

    switch(segment ) {
    case 0:      // red
        R = brightness;
        G = next;
        B = complement;
    break;
    case 1:     // yellow
        R = prev;
        G = brightness;
        B = complement;
    break;
    case 2:     // green
        R = complement;
        G = brightness;
        B = next;
    break;
    case 3:    // cyan
        R = complement;
        G = prev;
        B = brightness;
    break;
    case 4:    // blue
        R = next;
        G = complement;
        B = brightness;
    break;
   case 5:      // magenta
    default:
        R = brightness;
        G = complement;
        B = prev;
    break;
    }
}

void RGBLedManager::setRGB(uint8_t red, uint8_t green, uint8_t blue) {
    R = red * brightness / 255;
    G = green * brightness / 255;
    B = blue * brightness / 255;
}

void RGBLedManager::setColorWithParticles(uint16_t particles) {
    if (particles <= 10){
    hexToRGB(hexColors[0]); 
  } else if (particles <= 20) {
    hexToRGB(hexColors[1]); 
  } else if (particles <= 30) {
    hexToRGB(hexColors[2]); 
  } else if (particles <= 40){
    hexToRGB(hexColors[3]); 
  } else if (particles <= 50) {
    hexToRGB(hexColors[4]); 
  } else if (particles <= 60) {
    hexToRGB(hexColors[5]); 
  } else if (particles <= 70) {
    hexToRGB(hexColors[6]); 
  } else if (particles <= 80) {
    hexToRGB(hexColors[7]); 
  } else if (particles <= 90) {
    hexToRGB(hexColors[8]); 
  } else if (particles <= 100) {
    hexToRGB(hexColors[9]); 
  } else if (particles > 100) {
    hexToRGB(hexColors[10]);
  }
}