#include <iostream>
#include <string>
using namespace std;

class DataPlan {
    string planName;
    double monthlyCapMB, averageRatePerMB;
    double normalSpeedKbps, throttledSpeedKbps;
public:
    DataPlan(string n = "Basic", double cap = 1000, double rate = 0.05,
             double normal = 10000, double throttled = 128)
        : planName(n), monthlyCapMB(cap), averageRatePerMB(rate),
          normalSpeedKbps(normal), throttledSpeedKbps(throttled) {}
    double getCapMB() const { return monthlyCapMB; }
    double getOverageRate() const { return averageRatePerMB; }
    double getNormalSpeed() const { return normalSpeedKbps; }
    double getThrottledSpeed() const { return throttledSpeedKbps; }
};

class UsageMeter {
    string simNumber;
    double usedMB;
    DataPlan plan;
public:
    UsageMeter(string sim, DataPlan p) : simNumber(sim), usedMB(0), plan(p) {}
    void addUsage(double mb) { usedMB += mb; }
    double getUsedMB() const { return usedMB; }
    double getRemainingMB() const { return max(0.0, plan.getCapMB() - usedMB); }
    double getUsagePercent() const { return usedMB / plan.getCapMB() * 100; }
    double getOverageMB() const { return max(0.0, usedMB - plan.getCapMB()); }
    const DataPlan& getPlan() const { return plan; }
    string getSim() const { return simNumber; }
    void resetMonthly() { usedMB = 0; }
};

class ThrottlePolicy {                       // abstract class
public:
    virtual double applySpeed(const UsageMeter& m) = 0;
    virtual ~ThrottlePolicy() {}
};

class SpeedReductionPolicy : public ThrottlePolicy {
public:
    double applySpeed(const UsageMeter& m) override {
        return (m.getUsagePercent() >= 100) ? m.getPlan().getThrottledSpeed()
                                            : m.getPlan().getNormalSpeed();
    }
};

class HardCapPolicy : public ThrottlePolicy {
public:
    double applySpeed(const UsageMeter& m) override {
        return (m.getUsagePercent() >= 100) ? 0 : m.getPlan().getNormalSpeed();
    }
};