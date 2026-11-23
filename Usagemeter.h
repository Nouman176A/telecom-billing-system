
#ifndef USAGEMETER_H
#define USAGEMETER_H

class UsageMeter
{
private:
    double dataLimit;
    double usedData;

public:
    UsageMeter(double limit);

    void addUsage(double data);

    double getUsedData();
    double getRemainingData();
    double getUsagePercentage();

    void displayUsage();
};

#endif
