/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/phat_/Dropbox/IntelligenteSystemer/4.Semester/EmbeddedSystems/Exam/source/src/Exam.ino"
#include "IRreceiver.h"
#include "Growlight.h"
#include "Email.h"

void setup();
void loop();
#line 5 "c:/Users/phat_/Dropbox/IntelligenteSystemer/4.Semester/EmbeddedSystems/Exam/source/src/Exam.ino"
Screen screen;
WaterSensor waterSensor;
Photoresistor photoresistor;
Growlight growlight;
IRreceiver ir;
Email email;

// These values are float because they are calculated to percentage

void setup()
{
    // Variables for use over WiFi
    Particle.variable("waterLevel", waterSensor.getWaterLevel());
    Particle.variable("sendEmail", email.getEmailVariable());

    growlight.init();

    ir.enableIRIn();

    screen.init();
}

void loop()
{
    // Get the analog values and convert to percentages
    waterSensor.calculateWaterLevelPercentage();
    photoresistor.calculateLightLevelPercentage();

    email.checkToSendEmail(waterSensor);

    // Handles the changing of lower limits
    ir.userInput(screen, waterSensor, photoresistor);

    screen.updateScreen(waterSensor, photoresistor);

    growlight.toggleGrowlight(photoresistor);
}