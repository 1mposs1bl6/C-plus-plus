#ifndef TELEFON_H
#define TELEFON_H

#include <iostream>
#include <string>

using namespace std;

class telefon {
private:
  string model;
  string operatorName;
  int batteryLevel;
  bool isPhoneTurnedOn;
  bool isCurrentlyCalling;

public:
  telefon();
  telefon(string model, string operatorName, int batteryLevel);

  string getModel() { return model; }
  string getOperatorName() { return operatorName; }
  int getBatteryLevel() { return batteryLevel; }
  bool isOn() { return isPhoneTurnedOn; }
  bool isCalling() { return isCurrentlyCalling; }

  void setModel(string model) { this->model = model; }
  void setOperatorName(string operatorName) { this->operatorName = operatorName; }
  void setBatteryLevel(int batteryLevel) { this->batteryLevel = batteryLevel; }
  void setIsOn(bool isOn) { this->isPhoneTurnedOn = isOn; }
  void setIsCalling(bool isCalling) { this->isCurrentlyCalling = isCalling; }

  void turnOn();
  void turnOff();
  void makeCall();
  void describe();
};

#endif