#include <iostream>
#include "Subscriber.h"
using namespace std;

int main() {
    // Creating two Subscriber objects
    Subscriber s1("310260991820", "0300-1234567", "Ayesha", "Prepaid", true, 15.0);
    Subscriber s2("310260991821", "0321-7654321", "Bilal", "Postpaid", false, 0.0);

    // Show starting details
    s1.displayProfile();
    s2.displayProfile();

    // Test actions on first subscriber
    s1.topUp(10.0);
    s1.deductCharge(4.5);
    s1.requestEmergencyBalance(5.0);
    s1.displayProfile();

    // Test KYC check and top-up on second subscriber
    s2.topUp(20.0);
    s2.verifyKyc(true);
    s2.topUp(20.0);
    s2.displayProfile();

    return 0;
}