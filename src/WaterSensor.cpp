#include "WaterSensor.h"

void WaterSensor::calculateWaterLevelPercentage()
{
    waterLevel = analogRead(WATER_SENSOR_PIN);

    waterLevel = waterLevel / MAX_WATER_SENSOR_VALUE * 100;
}

void WaterSensor::updateOld()
{
    oldWaterLevel = waterLevel;
}