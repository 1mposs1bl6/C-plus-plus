#include "telefon.h"

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