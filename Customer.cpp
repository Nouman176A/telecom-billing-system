
#include <iostream>
#include "Subscriber.h"
using namespace std;

Subscriber::Subscriber(string id, string phone, string customerName,
                       string type, bool kyc, double initialBalance)
{
    imsi = id;
    phoneNumber = phone;
    name = customerName;
    accountType = type;
    kycVerified = kyc;
    balance = initialBalance;
}

void Subscriber::displayProfile()
{
    cout << "\n========== SUBSCRIBER PROFILE ==========\n";

    cout << "IMSI: " << imsi << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Name: " << name << endl;
    cout << "Account Type: " << accountType << endl;

    cout << "KYC Status: ";

    if (kycVerified)
        cout << "Verified\n";
    else
        cout << "Not Verified\n";

    cout << "Balance: " << balance << endl;

    cout << "========================================\n";
}

void Subscriber::topUp(double amount)
{
    if (amount <= 0)
    {
        cout << "\nInvalid top-up amount!\n";
        return;
    }

    if (accountType == "Prepaid" && !kycVerified)
    {
        cout << "\nKYC verification required before top-up!\n";
        return;
    }

    balance = balance + amount;

    cout << "\nTop-up successful!\n";
    cout << "Added Amount: " << amount << endl;
    cout << "New Balance: " << balance << endl;
}

void Subscriber::deductCharge(double amount)
{
    if (amount <= 0)
    {
        cout << "\nInvalid charge amount!\n";
        return;
    }

    if (balance >= amount)
    {
        balance = balance - amount;

        cout << "\nCharge deducted successfully!\n";
        cout << "Remaining Balance: " << balance << endl;
    }
    else
    {
        cout << "\nInsufficient balance!\n";
    }
}

void Subscriber::requestEmergencyBalance(double amount)
{
    if (amount <= 0)
    {
        cout << "\nInvalid emergency balance amount!\n";
        return;
    }

    if (accountType == "Prepaid")
    {
        if (!kycVerified)
        {
            cout << "\nKYC verification required!\n";
            return;
        }

        balance = balance + amount;

        cout << "\nEmergency balance added successfully!\n";
        cout << "Emergency Amount: " << amount << endl;
        cout << "New Balance: " << balance << endl;
    }
    else
    {
        cout << "\nEmergency balance is only available for prepaid accounts.\n";
    }
}

void Subscriber::verifyKyc(bool status)
{
    kycVerified = status;

    if (kycVerified)
        cout << "\nKYC verification completed successfully!\n";
    else
        cout << "\nKYC verification is not completed.\n";
}
