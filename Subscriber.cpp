#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
using namespace std;

class Subscriber {
private:
    string imsi;
    string phoneNumber;
    string name;
    string planType;     // "Prepaid" or "Postpaid"
    bool kycVerified;
    double balance;
    bool emergencyUsed;

public:
    // Constructor (runs when a Subscriber object is created)
    Subscriber(string subImsi, string subPhone, string subName, string subPlan, bool kyc, double startBalance);

    // Functions to get values (Encapsulation)
    string getName();
    double getBalance();

    // Functions to update account and wallet
    void verifyKyc(bool status);
    void topUp(double amount);
    void deductCharge(double amount);
    void requestEmergencyBalance(double amount);
    void displayProfile();
};

#endif