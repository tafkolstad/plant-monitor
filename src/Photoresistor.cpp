#include "Photoresistor.h"

void Photoresistor::calculateLightLevelPercentage()
{
    lightLevel = analogRead(PHOTORESISTOR_PIN);

    lightLevel = lightLevel / MAX_PHOTORESISTOR_VALUE * 100;
}

void Photoresistor::updateOld()
{
    oldLightLevel = lightLevel;
}