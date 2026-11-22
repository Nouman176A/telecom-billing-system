
#ifndef CDR_H
#define CDR_H

#include <string>
using namespace std;

// Parent class: UsageRecord
class UsageRecord {
private:
    string subscriberNumber;
    string recordID;

public:
    UsageRecord(string number, string id);

    string getSubscriberNumber();
    string getRecordID();

    void displayBasicInfo();

    virtual double calculateCost() = 0;

    virtual ~UsageRecord();
};

// Child class: VoiceCall
class VoiceCall : public UsageRecord {
private:
    int duration;
    double ratePerMinute;

public:
    VoiceCall(string number, string id, int time, double rate);

    double calculateCost() override;
    void displayCall();
};

// Child class: SMSRecord
class SMSRecord : public UsageRecord {
private:
    int messageCount;
    double ratePerSMS;

public:
    SMSRecord(string number, string id, int count, double rate);

    double calculateCost() override;
    void displaySMS();
};

// Child class: DataUsage
class DataUsage : public UsageRecord {
private:
    double dataUsedMB;
    double ratePerMB;

public:
    DataUsage(string number, string id, double data, double rate);

    double calculateCost() override;
    void displayDataUsage();
};

#endif
