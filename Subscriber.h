#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
using namespace std;

// Class 1: Handles SIM card & KYC verification
class SimProfile {
private:
    string imsi;
    string phoneNumber;
    bool kycVerified;

public:
    SimProfile();
    SimProfile(string subImsi, string subPhone, bool kyc);

    string getImsi();
    string getPhoneNumber();
    bool isKycVerified();
    void verifyKyc(bool status);
};

// Class 2: Handles prepaid/postpaid balance & emergency loan
class Wallet {
private:
    double balance;
    bool emergencyUsed;

public:
    Wallet();
    Wallet(double startBalance);

    double getBalance();
    void topUp(double amount, bool kycDone);
    void deductCharge(double amount, string planType);
    void requestEmergencyBalance(double amount, bool kycDone);
};

// Class 3: Main Subscriber class combining SimProfile and Wallet
class Subscriber {
private:
    string name;
    string planType;      // "Prepaid" or "Postpaid"
    SimProfile sim;       // Object of Class 1
    Wallet wallet;        // Object of Class 2

public:
    Subscriber(string subImsi, string subPhone, string subName, string subPlan, bool kyc, double startBalance);

    string getName();
    double getBalance();

    void verifyKyc(bool status);
    void topUp(double amount);
    void deductCharge(double amount);
    void requestEmergencyBalance(double amount);
    void displayProfile();
};

#endif