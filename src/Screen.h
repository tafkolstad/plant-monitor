#ifndef SCREEN_H
#define SCREEN_H

#include <SPI.h>
#include "libraries/ST7789/Arduino_ST7789.h"
#include "WaterSensor.h"
#include "Photoresistor.h"

class Screen
{
public:
    void drawScreen(WaterSensor &waterSensor, Photoresistor &photoresistor);
    void updateScreen(WaterSensor &waterSensor, Photoresistor &photoresistor);
    void init();

private:
    const int TFT_MOSI = A5;
    const int TFT_MISO = A4;
    const int TFT_CLK = A3;
    const int TFT_CS = A2;
    const int TFT_RST = A1;
    const int TFT_DC = A0;

    const int FULL_RECT_WIDTH = 200; // Because the rectangle that fills it is based on percentage values, and 100 was to little compared to the screen
    const int RECT_HEIGHT = 10;
    const int BIAS = 1; // To keep the display from updating all the time, causing a kind of "stutter" animation

    Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST, TFT_CS); // Using Hardware SPI
};

#endif /* SCREEN_H */