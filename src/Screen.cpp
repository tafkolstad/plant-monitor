#include "Screen.h"

void Screen::drawScreen(WaterSensor &waterSensor, Photoresistor &photoresistor)
{
    double waterLevel = waterSensor.getWaterLevel();
    int lightLevel = photoresistor.getLightLevel();

    // Draw information about water
    tft.fillScreen(BLACK);
    tft.setCursor(0, 0);
    tft.setTextColor(BLUE);
    tft.setTextSize(3);
    tft.println("Water level:");
    tft.println((int)waterLevel);   // Only show integers
    tft.drawRect(0, 50, FULL_RECT_WIDTH, RECT_HEIGHT, BLUE);
    tft.fillRect(0, 50, waterLevel * 2, RECT_HEIGHT, BLUE); // Fill the rectangle with the corresponding amount of water
    tft.drawFastVLine(waterSensor.getMinimumWaterLevel() * 2, 50, RECT_HEIGHT, RED);    // This is the limit where you will receive an e-mail if it is reached

    // Draw information about light
    tft.setCursor(0, 70);
    tft.setTextColor(YELLOW);
    tft.println("Light level:");
    tft.println((int)lightLevel);   // Only show integers
    tft.drawRect(0, 120, FULL_RECT_WIDTH, RECT_HEIGHT, YELLOW);
    tft.fillRect(0, 120, lightLevel * 2, RECT_HEIGHT, YELLOW); // Fill the rectangle with the corresponding amount of light
    tft.drawFastVLine(photoresistor.getMinimumLightLevel() * 2, 120, RECT_HEIGHT, RED); // The limit for when the growlight should turn on
}

void Screen::updateScreen(WaterSensor &waterSensor, Photoresistor &photoresistor)
{
    const float oldWaterLevel = waterSensor.getOldWaterLevel();
    const double waterLevel = waterSensor.getWaterLevel();
    const int oldLightLevel = photoresistor.getOldLightLevel();
    const int lightLevel = photoresistor.getLightLevel();

    // If the change in any of the levels is high enough
    if (oldWaterLevel > waterLevel + BIAS || oldWaterLevel < waterLevel - BIAS || oldLightLevel > lightLevel + BIAS || oldLightLevel < lightLevel - BIAS)
    {
        drawScreen(waterSensor, photoresistor);

        waterSensor.updateOld();
        photoresistor.updateOld();

        Particle.publish("water", String(waterLevel), PRIVATE);
    }
}

void Screen::init()
{
    tft.init(135, 240);
    tft.setRotation(3);
    tft.setFont(COMICS_8);
}