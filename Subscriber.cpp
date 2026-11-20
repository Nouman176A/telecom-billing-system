#include "Subscriber.h"
#include <iostream>
using namespace std;

// Constructor: sets starting values for a new Subscriber
Subscriber::Subscriber(string subImsi, string subPhone, string subName, string subPlan, bool kyc, double startBalance) {
    imsi = subImsi;
    phoneNumber = subPhone;
    name = subName;
    planType = subPlan;
    kycVerified = kyc;

    if (startBalance >= 0) {
        balance = startBalance;
    } else {
        balance = 0;
    }

    emergencyUsed = false;
}

string Subscriber::getName() {
    return name;
}

double Subscriber::getBalance() {
    return balance;
}

void Subscriber::verifyKyc(bool status) {
    kycVerified = status;
    cout << name << " KYC status updated." << endl;
}

void Subscriber::topUp(double amount) {
    if (kycVerified == false) {
        cout << "Cannot top up for " << name << ": KYC is not verified." << endl;
        return;
    }

    if (amount <= 0) {
        cout << "Top-up amount must be greater than 0." << endl;
        return;
    }

    balance = balance + amount;
    cout << "Top-up successful! Added $" << amount << " to " << name << ". New balance: $" << balance << endl;
}

void Subscriber::deductCharge(double amount) {
    if (amount <= 0) {
        cout << "Invalid charge amount." << endl;
        return;
    }

    if (planType == "Prepaid" && balance < amount) {
        cout << "Not enough prepaid balance for " << name << "." << endl;
        return;
    }

    balance = balance - amount;
    cout << "Deducted $" << amount << " from " << name << ". Remaining balance: $" << balance << endl;
}

void Subscriber::requestEmergencyBalance(double amount) {
    if (kycVerified == false) {
        cout << "Emergency balance denied for " << name << ": KYC not verified." << endl;
        return;
    }

    if (emergencyUsed == true) {
        cout << "Emergency balance already used by " << name << "." << endl;
        return;
    }

    if (amount <= 0 || amount > 10) {
        cout << "Emergency balance must be between $1 and $10." << endl;
        return;
    }

    balance = balance + amount;
    emergencyUsed = true;
    cout << "Emergency balance of $" << amount << " added for " << name << ". New balance: $" << balance << endl;
}

void Subscriber::displayProfile() {
    cout << "----------------------------" << endl;
    cout << "Name:       " << name << endl;
    cout << "Phone:      " << phoneNumber << endl;
    cout << "IMSI:       " << imsi << endl;
    cout << "Plan:       " << planType << endl;
    cout << "KYC Done:   " << (kycVerified ? "Yes" : "No") << endl;
    cout << "Balance:    $" << balance << endl;
    cout << "----------------------------" << endl;
}