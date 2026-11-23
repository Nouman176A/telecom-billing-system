
#include <iostream>
#include "AlertManager.h"
using namespace std;

void AlertManager::checkAlert(double oldUsage, double newUsage)
{
    if (oldUsage < 80 && newUsage >= 80)
    {
        cout << "\nWARNING: Customer has used 80% of data!\n";
    }

    if (oldUsage < 90 && newUsage >= 90)
    {
        cout << "\nCRITICAL ALERT: Customer has used 90% of data!\n";
    }

    if (oldUsage < 100 && newUsage >= 100)
    {
        cout << "\nALERT: Customer has reached the data limit!\n";
    }
}
