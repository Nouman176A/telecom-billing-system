
#include <iostream>
#include <iomanip>
#include "UsageMeter.h"
using namespace std;

UsageMeter::UsageMeter(double limit)
{
    dataLimit = limit;
    usedData = 0;
}

void UsageMeter::addUsage(double data)
{
    if (data <= 0)
    {
        cout << "\nInvalid data amount!\n";
        return;
    }

    usedData = usedData + data;

    cout << "\nData usage added successfully!\n";
}

double UsageMeter::getUsedData()
{
    return usedData;
}

double UsageMeter::getRemainingData()
{
    double remaining = dataLimit - usedData;

    if (remaining < 0)
        return 0;

    return remaining;
}

double UsageMeter::getUsagePercentage()
{
    return (usedData / dataLimit) * 100;
}

void UsageMeter::displayUsage()
{
    cout << fixed << setprecision(2);

    cout << "\n------ DATA USAGE REPORT ------\n";

    cout << "Data Limit: " << dataLimit << " GB\n";
    cout << "Used Data: " << usedData << " GB\n";
    cout << "Remaining Data: " << getRemainingData() << " GB\n";
    cout << "Usage Percentage: " << getUsagePercentage() << "%\n";
}
