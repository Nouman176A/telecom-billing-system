
#include "CDR.h"
#include <iostream>
using namespace std;

// UsageRecord implementation
UsageRecord::UsageRecord(string number, string id) {
    subscriberNumber = number;
    recordID = id;
}

string UsageRecord::getSubscriberNumber() {
    return subscriberNumber;
}

string UsageRecord::getRecordID() {
    return recordID;
}

void UsageRecord::displayBasicInfo() {
    cout << "Subscriber Number: " << subscriberNumber << endl;
    cout << "Record ID: " << recordID << endl;
}

UsageRecord::~UsageRecord() {
}

// VoiceCall implementation
VoiceCall::VoiceCall(string number, string id, int time, double rate)
    : UsageRecord(number, id) {
    duration = time;
    ratePerMinute = rate;
}

double VoiceCall::calculateCost() {
    return (duration / 60.0) * ratePerMinute;
}

void VoiceCall::displayCall() {
    cout << "\n----- Voice Call Details -----" << endl;
    displayBasicInfo();
    cout << "Call Duration: " << duration << " seconds" << endl;
    cout << "Rate Per Minute: $" << ratePerMinute << endl;
    cout << "Total Call Cost: $" << calculateCost() << endl;
}

// SMSRecord implementation
SMSRecord::SMSRecord(string number, string id, int count, double rate)
    : UsageRecord(number, id) {
    messageCount = count;
    ratePerSMS = rate;
}

double SMSRecord::calculateCost() {
    return messageCount * ratePerSMS;
}

void SMSRecord::displaySMS() {
    cout << "\n----- SMS Record Details -----" << endl;
    displayBasicInfo();
    cout << "Number of Messages: " << messageCount << endl;
    cout << "Rate Per SMS: $" << ratePerSMS << endl;
    cout << "Total SMS Cost: $" << calculateCost() << endl;
}

// DataUsage implementation
DataUsage::DataUsage(string number, string id, double data, double rate)
    : UsageRecord(number, id) {
    dataUsedMB = data;
    ratePerMB = rate;
}

double DataUsage::calculateCost() {
    return dataUsedMB * ratePerMB;
}

void DataUsage::displayDataUsage() {
    cout << "\n----- Data Usage Details -----" << endl;
    displayBasicInfo();
    cout << "Data Used: " << dataUsedMB << " MB" << endl;
    cout << "Rate Per MB: $" << ratePerMB << endl;
    cout << "Total Data Cost: $" << calculateCost() << endl;
}
