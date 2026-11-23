
#include <iostream>
#include "ThrottlingManager.h"
using namespace std;

double ThrottlingManager::calculateSpeed(double percentage, double normalSpeed)
{
    if (percentage >= 100)
    {
        return 1;
    }
    else if (percentage >= 90)
    {
        return 10;
    }
    else
    {
        return normalSpeed;
    }
}

void ThrottlingManager::displaySpeed(double speed)
{
    cout << "\nCurrent Internet Speed: " << speed << " Mbps\n";

    if (speed == 1)
    {
        cout << "Internet speed is heavily throttled.\n";
    }
    else if (speed == 10)
    {
        cout << "Internet speed has been reduced.\n";
    }
    else
    {
        cout << "Normal internet speed is available.\n";
    }
}
