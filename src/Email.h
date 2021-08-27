#ifndef EMAIL_H
#define EMAIL_H

#include "WaterSensor.h"

class Email
{
public:
    void checkToSendEmail(WaterSensor &waterSensor);
    const inline int getEmailVariable() { return sendEmail; }

private:
    int sendEmail = 0;
    int check = 0;
    int oldCheck = 0;
};

#endif /* EMAIL_H */