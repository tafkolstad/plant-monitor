#ifndef PHOTORESISTOR_H
#define PHOTORESISTOR_H

#include <Arduino.h>

class Photoresistor
{
public:
    const inline int getLightLevel() { return lightLevel; }
    const inline int getOldLightLevel() { return oldLightLevel; }
    const inline int getMinimumLightLevel() { return minimumLightLevel; }
    void calculateLightLevelPercentage();
    void updateOld();
    const inline bool isTooDark() { return lightLevel < minimumLightLevel; }
    inline void increaseLightLevelLimit() { minimumLightLevel += 5; }
    inline void decreaseLightLevelLimit() { minimumLightLevel -= 5; }

private:
    const int PHOTORESISTOR_PIN = A7;
    const int MAX_PHOTORESISTOR_VALUE = 4095;

    float lightLevel = 0;
    float oldLightLevel = 0;

    int minimumLightLevel = 40; // Lowest light percentage before grow light turns on
};

#endif /* PHOTORESISTOR_H */