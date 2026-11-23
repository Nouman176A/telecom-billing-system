
#ifndef THROTTLINGMANAGER_H
#define THROTTLINGMANAGER_H

class ThrottlingManager
{
public:
    double calculateSpeed(double percentage, double normalSpeed);
    void displaySpeed(double speed);
};

#endif
