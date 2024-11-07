#include "telefon.h"

telefon::telefon() : telefon("Модель телефона", "Оператор", 100) {}

telefon::telefon(string model, string operatorName, int batteryLevel) {
  this->model = model;
  this->operatorName = operatorName;
  this->batteryLevel = batteryLevel;
  this->isPhoneTurnedOn = false;
  this->isCurrentlyCalling = false;
}

void telefon::turnOn() {
  isPhoneTurnedOn = true;
  cout << "Телефон включен" << endl;
}

void telefon::turnOff() {
  isPhoneTurnedOn = false;
  cout << "Телефон выключен" << endl;
}

void telefon::makeCall() {
  if (isPhoneTurnedOn) {
    isCurrentlyCalling = true;
    cout << "Звонок идет" << endl;
  } else {
    cout << "Телефон выключен" << endl;
  }
}

void telefon::describe() {
  cout << "Модель: " << model << ", Оператор: " << operatorName << ", Батарея: " << batteryLevel << "%" << endl;
}