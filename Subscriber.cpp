#include "Subscriber.h"
#include <iostream>
using namespace std;

// ================= SimProfile Class =================

SimProfile::SimProfile() {
    imsi = "";
    phoneNumber = "";
    kycVerified = false;
}

SimProfile::SimProfile(string subImsi, string subPhone, bool kyc) {
    imsi = subImsi;
    phoneNumber = subPhone;
    kycVerified = kyc;
}

string SimProfile::getImsi() {
    return imsi;
}

string SimProfile::getPhoneNumber() {
    return phoneNumber;
}

bool SimProfile::isKycVerified() {
    return kycVerified;
}

void SimProfile::verifyKyc(bool status) {
    kycVerified = status;
}

// ================= Wallet Class =================

Wallet::Wallet() {
    balance = 0;
    emergencyUsed = false;
}

Wallet::Wallet(double startBalance) {
    if (startBalance >= 0) {
        balance = startBalance;
    } else {
        balance = 0;
    }
    emergencyUsed = false;
}

double Wallet::getBalance() {
    return balance;
}

void Wallet::topUp(double amount, bool kycDone) {
    if (kycDone == false) {
        cout << "Top-up failed: KYC is not verified." << endl;
        return;
    }

    if (amount <= 0) {
        cout << "Top-up amount must be greater than 0." << endl;
        return;
    }

    balance = balance + amount;
    cout << "Top-up successful! Added $" << amount << ". New balance: $" << balance << endl;
}

void Wallet::deductCharge(double amount, string planType) {
    if (amount <= 0) {
        cout << "Invalid charge amount." << endl;
        return;
    }

    if (planType == "Prepaid" && balance < amount) {
        cout << "Not enough prepaid balance." << endl;
        return;
    }

    balance = balance - amount;
    cout << "Deducted $" << amount << ". Remaining balance: $" << balance << endl;
}

void Wallet::requestEmergencyBalance(double amount, bool kycDone) {
    if (kycDone == false) {
        cout << "Emergency balance denied: KYC not verified." << endl;
        return;
    }

    if (emergencyUsed == true) {
        cout << "Emergency balance already used." << endl;
        return;
    }

    if (amount <= 0 || amount > 10) {
        cout << "Emergency balance must be between $1 and $10." << endl;
        return;
    }

    balance = balance + amount;
    emergencyUsed = true;
    cout << "Emergency balance of $" << amount << " added. New balance: $" << balance << endl;
}

// ================= Subscriber Class =================

Subscriber::Subscriber(string subImsi, string subPhone, string subName, string subPlan, bool kyc, double startBalance) {
    name = subName;
    planType = subPlan;
    sim = SimProfile(subImsi, subPhone, kyc);
    wallet = Wallet(startBalance);
}

string Subscriber::getName() {
    return name;
}

double Subscriber::getBalance() {
    return wallet.getBalance();
}

void Subscriber::verifyKyc(bool status) {
    sim.verifyKyc(status);
    cout << name << " KYC status updated." << endl;
}

void Subscriber::topUp(double amount) {
    cout << "[" << name << "] ";
    wallet.topUp(amount, sim.isKycVerified());
}

void Subscriber::deductCharge(double amount) {
    cout << "[" << name << "] ";
    wallet.deductCharge(amount, planType);
}

void Subscriber::requestEmergencyBalance(double amount) {
    cout << "[" << name << "] ";
    wallet.requestEmergencyBalance(amount, sim.isKycVerified());
}

void Subscriber::displayProfile() {
    cout << "----------------------------" << endl;
    cout << "Name:       " << name << endl;
    cout << "Phone:      " << sim.getPhoneNumber() << endl;
    cout << "IMSI:       " << sim.getImsi() << endl;
    cout << "Plan:       " << planType << endl;
    cout << "KYC Done:   " << (sim.isKycVerified() ? "Yes" : "No") << endl;
    cout << "Balance:    $" << wallet.getBalance() << endl;
    cout << "----------------------------" << endl;
}