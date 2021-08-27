#include "Growlight.h"
#include <Arduino.h>

void Growlight::toggleGrowlight(Photoresistor &photoresistor)
{
    // Turn on a growlight if there is too little light
    if (photoresistor.isTooDark())
    {
        digitalWrite(GROWLIGHT_PIN, HIGH);
    }
    else
    {
        digitalWrite(GROWLIGHT_PIN, LOW);
    }
}

void Growlight::init()
{
    pinMode(GROWLIGHT_PIN, OUTPUT);
}