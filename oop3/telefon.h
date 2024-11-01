#ifndef TELEFON_H
#define TELEFON_H

#include <iostream>
#include <string>

using namespace std;

class Telefon {
private:
    string model;
    string operatorName;
    int batteryLevel;
    bool isPhoneTurnedOn;
    bool isCurrentlyCalling;

public:
    // геттеры
    string getModel() { return model; }
    string getOperatorName() { return operatorName; }
    int getBatteryLevel() { return batteryLevel; }
    bool isOn() { return isPhoneTurnedOn; }
    bool isCalling() { return isCurrentlyCalling; }

    // сеттеры
    void setModel(string newModel) { model = newModel; }
    void setOperatorName(string newOperatorName) { operatorName = newOperatorName; }
    void setBatteryLevel(int newBatteryLevel) { batteryLevel = newBatteryLevel; }
    void setIsOn(bool newIsOn) { isPhoneTurnedOn = newIsOn; }
    void setIsCalling(bool newIsCalling) { isCurrentlyCalling = newIsCalling; }

    void turnOn();
    void turnOff();
    void makeCall();
    void describe();
};

#endif