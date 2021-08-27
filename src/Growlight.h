#ifndef GROWLIGHT_H
#define GROWLIGHT_H

#include "Photoresistor.h"
#include <Arduino.h>

class Growlight
{
public:
    void init();
    void toggleGrowlight(Photoresistor &photoresistor);

private:
    const uint16_t GROWLIGHT_PIN = D0;
};

#endif /* GROWLIGHT_H */