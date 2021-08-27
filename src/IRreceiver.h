#ifndef IRRECEIVER_H
#define IRRECEIVER_H

#include "libraries/IRremote/src/IRremote.h"
#include "Screen.h"
#include "WaterSensor.h"
#include "Photoresistor.h"
#include <memory>

class IRreceiver
{
public:
    IRreceiver();

    void enableIRIn();
    void userInput(Screen &screen, WaterSensor &waterSensor, Photoresistor &photoresistor);

private:
    const int IR_PIN = D1;
    const int WATER_BORDER_MINUS = 16769055; // The value for volume- on the controller
    const int WATER_BORDER_PLUS = 16754775;  // The value for volume+ on the controller
    const int LIGHT_BORDER_MINUS = 16753245; // The value for ch- on the controller
    const int LIGHT_BORDER_PLUS = 16769565;  // The value for ch+ on the controller
    const int LIMIT_LOW = 0;                 // Lowest possible value for the limit in the animated rectangles
    const int LIMIT_HIGH = 100;              // Highest possible value for the limit in the animated rectangles

    std::unique_ptr<IRrecv> irrecv;
    decode_results results;
};

#endif /* IRRECEIVER_H */