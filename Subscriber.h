
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
using namespace std;

class Subscriber
{
private:
    string imsi;
    string phoneNumber;
    string name;
    string accountType;
    bool kycVerified;
    double balance;

public:
    Subscriber(string id, string phone, string customerName,
               string type, bool kyc, double initialBalance);

    void displayProfile();

    void topUp(double amount);

    void deductCharge(double amount);

    void requestEmergencyBalance(double amount);

    void verifyKyc(bool status);
};

#endif
