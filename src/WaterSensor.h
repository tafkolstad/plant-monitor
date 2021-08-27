#ifndef WATERSENSOR_H
#define WATERSENSOR_H

#include <Arduino.h>

class WaterSensor
{
public:
    const inline double getWaterLevel() { return waterLevel; }
    const inline float getOldWaterLevel() { return oldWaterLevel; }
    const inline int getMinimumWaterLevel() { return minimumWaterLevel; }
    void calculateWaterLevelPercentage();
    void updateOld();
    const inline bool isWaterLevelLow() { return waterLevel < minimumWaterLevel; }
    inline void increaseWaterLevelLimit() { minimumWaterLevel += 5; }
    inline void decreaseWaterLevelLimit() { minimumWaterLevel -= 5; }

private:
    const int WATER_SENSOR_PIN = A6;
    const int MAX_WATER_SENSOR_VALUE = 3500; // The highest value possible is actually higher (at least on my sensor), but it slowly settled at about 3500

    double waterLevel = 0; // Has to be double to be used with Particle.variable

    float oldWaterLevel = 0; // Old values are used when checking if display should be updated

    int minimumWaterLevel = 25; // Lowest water percentage before an e-mail is sent
};

#endif /* WATERSENSOR_H */