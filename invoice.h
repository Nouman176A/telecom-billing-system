#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string customerName;
    string phoneNumber;
    int callMinutes;
    int dataMB;
    int smsCount;
    double subtotal;
    double discount;
    double tax;
    double total;

public:
    Invoice(string name, string phone, int calls, int data, int sms);   // constructor
    ~Invoice();                                                         // destructor

    void calculateSubtotal();
    void applyDiscount();
    void calculateTax();
    void calculateTotal();
    void printInvoice();
};

#endif