#ifndef TELEFON_H
#define TELEFON_H

#include <iostream>
#include <string>

using namespace std;

class telefon {
private:
  char* model;
  string operatorName;
  int batteryLevel;
  bool isPhoneTurnedOn;
  bool isCurrentlyCalling;

public:
  telefon();
  telefon(char* model, string operatorName, int batteryLevel);
  telefon(const telefon& other);
  ~telefon();

  char* getModel() const;
  string getOperatorName() { return operatorName; }
  int getBatteryLevel() { return batteryLevel; }
  bool isOn() { return isPhoneTurnedOn; }
  bool isCalling() { return isCurrentlyCalling; }

  void setModel(const char* model);
  void setOperatorName(string operatorName) { this->operatorName = operatorName; }
  void setBatteryLevel(int batteryLevel) { this->batteryLevel = batteryLevel; }
  void setIsOn(bool isOn) { this->isPhoneTurnedOn = isOn; }
  void setIsCalling(bool isCalling) { this->isCurrentlyCalling = isCalling; }

  void turnOn();
  void turnOff();
  void makeCall();
  void describe();

  bool operator==(const telefon& other) const;
  bool operator!=(const telefon& other) const;
  bool operator>(const telefon& other) const;
  bool operator<(const telefon& other) const;
  friend ostream& operator<<(ostream& os, const telefon& telefon);
  friend istream& operator>>(istream& is, telefon& telefon);
};

#endif