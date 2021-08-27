#include "Email.h"

void Email::checkToSendEmail(WaterSensor &waterSensor)
{
    check = waterSensor.isWaterLevelLow();

    // Only send one e-mail, and only if the water level is lower than it should
    if (check == 1 && oldCheck == 0)
    {
        oldCheck = check;

        Particle.publish("email", "send", PRIVATE);
    }
    else
    {
        if (!waterSensor.isWaterLevelLow())
        {
            oldCheck = check;
        }
    }
}