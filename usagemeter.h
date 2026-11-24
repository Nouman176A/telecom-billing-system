#ifndef USAGEMETER_H
#define USAGEMETER_H

#include <string>
using namespace std;

class UsageMeter {
private:
    string subscriberId;
    double monthlyLimitMB;
    double usedDataMB;
    double normalSpeedMbps;
    double throttledSpeedMbps;
    bool isThrottled;
    bool alert50Sent;
    bool alert80Sent;
    bool alert100Sent;
    double overageMB;

    void checkAlerts();
    void updateThrottling();

public:
    UsageMeter();
    UsageMeter(string id, double limitMB, double normalSpeed, double throttledSpeed);

    void addUsage(double dataMB);
    void sendAlert(int percent);
    void throttleSpeed();
    void restoreSpeed();
    void resetCycle();
    double calculateOverageCharges(double ratePerMB);

    // Getters
    string getSubscriberId();
    double getMonthlyLimitMB();
    double getUsedDataMB();
    double getRemainingDataMB();
    double getCurrentSpeedMbps();
    bool getIsThrottled();
    double getOverageMB();

    // Setters
    void setMonthlyLimitMB(double limitMB);
    void setNormalSpeedMbps(double speed);
    void setThrottledSpeedMbps(double speed);

    void displayStatus();
};

#endif