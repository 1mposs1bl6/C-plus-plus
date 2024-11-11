#include "telefon.h"

telefon::telefon() : telefon("iPhone", "Киевстар", 100) {} 

telefon::telefon(string model, string operatorName, int batteryLevel) {
  this->model = model;
  this->operatorName = operatorName;
  this->batteryLevel = batteryLevel;
  this->isPhoneTurnedOn = false;
  this->isCurrentlyCalling = false;
}

telefon::telefon(const telefon& other) {
  this->model = other.model;
  this->operatorName = other.operatorName;
  this->batteryLevel = other.batteryLevel;
  this->isPhoneTurnedOn = other.isPhoneTurnedOn;
  this->isCurrentlyCalling = other.isCurrentlyCalling;
}

void telefon::turnOn() {
  isPhoneTurnedOn = true;
  cout << "Телефон включен!" << endl;
}

void telefon::turnOff() {
  isPhoneTurnedOn = false;
  cout << "Телефон выключен." << endl;
}

void telefon::makeCall() {
  if (isPhoneTurnedOn) {
    isCurrentlyCalling = true;
    cout << "Звонок идет!" << endl;
  } else {
    cout << "Телефон выключен." << endl;
  }
}

void telefon::describe() {
  cout << "Модель: " << model << ", Оператор: " << operatorName << ", Батарея: " << batteryLevel << "%" << endl;
}

bool telefon::operator==(const telefon& other) const {
  return (model == other.model && operatorName == other.operatorName && batteryLevel == other.batteryLevel);
}

bool telefon::operator!=(const telefon& other) const {
  return !(*this == other);
}

bool telefon::operator>(const telefon& other) const {
  return (batteryLevel > other.batteryLevel);
}

bool telefon::operator<(const telefon& other) const {
  return (batteryLevel < other.batteryLevel);
}

ostream& operator<<(ostream& os, const telefon& telefon) {
  os << "Модель: " << telefon.getModel() << endl;
  os << "Оператор: " << telefon.getOperatorName() << endl;
  os << "Батарея: " << telefon.getBatteryLevel() << "%" << endl;
  return os;
}

istream& operator>>(istream& is, telefon& telefon) {
  string model, operatorName;
  int batteryLevel;

  cout << "Введите модель телефона: ";
  getline(is, model);
  cout << "Введите оператора: ";
  getline(is, operatorName);
  cout << "Введите уровень заряда батареи: ";
  is >> batteryLevel;

  telefon.setModel(model);
  telefon.setOperatorName(operatorName);
  telefon.setBatteryLevel(batteryLevel);

  return is;
}