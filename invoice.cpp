// invoice.cpp
// Body (working) of the constructor, destructor and member functions.

#include "invoice.h"

// Constructor: sets the values when the object is created
Invoice::Invoice(string name, string phone, int calls, int data, int sms) {
    customerName = name;
    phoneNumber = phone;
    callMinutes = calls;
    dataMB = data;
    smsCount = sms;
    subtotal = 0;
    discount = 0;
    tax = 0;
    total = 0;
}

// Destructor: runs automatically when the object is destroyed
Invoice::~Invoice() {
    cout << "Invoice object destroyed." << endl;
}

// Step 1: add up all the usage charges
void Invoice::calculateSubtotal() {
    double callCharges = callMinutes * 3;      // Rs.3 per minute
    double dataCharges = dataMB * 0.25;        // Rs.0.25 per MB
    double smsCharges = smsCount * 0.5;        // Rs.0.5 per SMS
    subtotal = callCharges + dataCharges + smsCharges;
}

// Step 2: promo discount (10%)
void Invoice::applyDiscount() {
    discount = subtotal * 10 / 100;
}

// Step 3: tax (15% GST) on the amount after discount
void Invoice::calculateTax() {
    tax = (subtotal - discount) * 15 / 100;
}

// Step 4: final total
void Invoice::calculateTotal() {
    total = subtotal - discount + tax;
}

// Step 5: print the invoice
void Invoice::printInvoice() {
    cout << "======= TELECOM INVOICE =======" << endl;
    cout << "Customer : " << customerName << endl;
    cout << "Phone    : " << phoneNumber << endl;
    cout << "-------------------------------" << endl;
    cout << "Calls    : " << callMinutes << " min x 3    = " << callMinutes * 3 << endl;
    cout << "Data     : " << dataMB << " MB x 0.25 = " << dataMB * 0.25 << endl;
    cout << "SMS      : " << smsCount << " x 0.5      = " << smsCount * 0.5 << endl;
    cout << "-------------------------------" << endl;
    cout << "Subtotal : " << subtotal << endl;
    cout << "Discount : -" << discount << endl;
    cout << "Tax      : " << tax << endl;
    cout << "TOTAL    : Rs. " << total << endl;
    cout << "===============================" << endl;
}