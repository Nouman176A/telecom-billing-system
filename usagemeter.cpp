#include "UsageMeter.h"
#include <iostream>
using namespace std;

UsageMeter::UsageMeter() {
    subscriberId = "SUB-000";
    monthlyLimitMB = 1024.0;
    usedDataMB = 0.0;
    normalSpeedMbps = 50.0;
    throttledSpeedMbps = 2.0;
    isThrottled = false;
    alert50Sent = false;
    alert80Sent = false;
    alert100Sent = false;
    overageMB = 0.0;
}

UsageMeter::UsageMeter(string id, double limitMB, double normalSpeed, double throttledSpeed) {
    subscriberId = id;
    monthlyLimitMB = limitMB;
    usedDataMB = 0.0;
    normalSpeedMbps = normalSpeed;
    throttledSpeedMbps = throttledSpeed;
    isThrottled = false;
    alert50Sent = false;
    alert80Sent = false;
    alert100Sent = false;
    overageMB = 0.0;
}

void UsageMeter::addUsage(double dataMB) {
    if (dataMB <= 0) {
        cout << "Invalid data usage amount.\n";
        return;
    }

    usedDataMB += dataMB;

    if (usedDataMB > monthlyLimitMB) {
        overageMB = usedDataMB - monthlyLimitMB;
    }

    checkAlerts();
    updateThrottling();
}

void UsageMeter::checkAlerts() {
    if (monthlyLimitMB <= 0) {
        return;
    }

    double usagePercent = (usedDataMB / monthlyLimitMB) * 100.0;

    if (usagePercent >= 50.0 && !alert50Sent) {
        alert50Sent = true;
        sendAlert(50);
    }

    if (usagePercent >= 80.0 && !alert80Sent) {
        alert80Sent = true;
        sendAlert(80);
    }

    if (usagePercent >= 100.0 && !alert100Sent) {
        alert100Sent = true;
        sendAlert(100);
    }
}

void UsageMeter::sendAlert(int percent) {
    cout << "[Alert] Subscriber " << subscriberId
         << " has used " << percent << "% of monthly data ("
         << usedDataMB << " MB / " << monthlyLimitMB << " MB).\n";
}

void UsageMeter::updateThrottling() {
    if (usedDataMB >= monthlyLimitMB && !isThrottled) {
        throttleSpeed();
    }
}

void UsageMeter::throttleSpeed() {
    isThrottled = true;
    cout << "[Throttle] Speed reduced to " << throttledSpeedMbps
         << " Mbps for subscriber " << subscriberId << ".\n";
}

void UsageMeter::restoreSpeed() {
    isThrottled = false;
    cout << "[Throttle] Normal speed (" << normalSpeedMbps
         << " Mbps) restored for subscriber " << subscriberId << ".\n";
}

void UsageMeter::resetCycle() {
    usedDataMB = 0.0;
    overageMB = 0.0;
    alert50Sent = false;
    alert80Sent = false;
    alert100Sent = false;
    restoreSpeed();
}

double UsageMeter::calculateOverageCharges(double ratePerMB) {
    if (overageMB <= 0 || ratePerMB <= 0) {
        return 0.0;
    }
    return overageMB * ratePerMB;
}

string UsageMeter::getSubscriberId() {
    return subscriberId;
}

double UsageMeter::getMonthlyLimitMB() {
    return monthlyLimitMB;
}

double UsageMeter::getUsedDataMB() {
    return usedDataMB;
}

double UsageMeter::getRemainingDataMB() {
    double remaining = monthlyLimitMB - usedDataMB;
    if (remaining < 0) {
        return 0.0;
    }
    return remaining;
}

double UsageMeter::getCurrentSpeedMbps() {
    if (isThrottled) {
        return throttledSpeedMbps;
    }
    return normalSpeedMbps;
}

bool UsageMeter::getIsThrottled() {
    return isThrottled;
}

double UsageMeter::getOverageMB() {
    return overageMB;
}

void UsageMeter::setMonthlyLimitMB(double limitMB) {
    if (limitMB > 0) {
        monthlyLimitMB = limitMB;
    }
}

void UsageMeter::setNormalSpeedMbps(double speed) {
    if (speed > 0) {
        normalSpeedMbps = speed;
    }
}

void UsageMeter::setThrottledSpeedMbps(double speed) {
    if (speed >= 0) {
        throttledSpeedMbps = speed;
    }
}

void UsageMeter::displayStatus() {
    cout << "Subscriber ID: " << subscriberId << "\n";
    cout << "Used Data: " << usedDataMB << " MB / " << monthlyLimitMB << " MB\n";
    cout << "Overage Data: " << overageMB << " MB\n";
    cout << "Current Speed: " << getCurrentSpeedMbps() << " Mbps\n";
    cout << "Throttled: " << (isThrottled ? "Yes" : "No") << "\n";
}