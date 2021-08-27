#include "IRreceiver.h"

IRreceiver::IRreceiver()
{
    std::make_unique<IRrecv>(IR_PIN);
}

void IRreceiver::enableIRIn()
{
    irrecv->enableIRIn();
}

void IRreceiver::userInput(Screen &screen, WaterSensor &waterSensor, Photoresistor &photoresistor)
{
    if (irrecv->decode(&results))
    {
        int minimumWaterLevel = waterSensor.getMinimumWaterLevel();
        int minimumLightLevel = photoresistor.getMinimumLightLevel();

        // Increase/decrease the limit, and make sure the line doesn't go outside the rectangle
        if ((int)results.value == WATER_BORDER_MINUS && minimumWaterLevel > LIMIT_LOW)
        {
            waterSensor.decreaseWaterLevelLimit();
        }
        else if ((int)results.value == WATER_BORDER_PLUS && minimumWaterLevel < LIMIT_HIGH)
        {
            waterSensor.increaseWaterLevelLimit();
        }
        else if ((int)results.value == LIGHT_BORDER_MINUS && minimumLightLevel > LIMIT_LOW)
        {
            photoresistor.decreaseLightLevelLimit();
        }
        else if ((int)results.value == LIGHT_BORDER_PLUS && minimumLightLevel < LIMIT_HIGH)
        {
            photoresistor.increaseLightLevelLimit();
        }

        screen.drawScreen(waterSensor, photoresistor);

        irrecv->resume();
    }
}