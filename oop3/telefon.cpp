#include "telefon.h"

void Telefon::turnOn() {
    isPhoneTurnedOn = true;
    cout << "Телефон включен." << endl;
}

void Telefon::turnOff() {
    isPhoneTurnedOn = false;
    cout << "Телефон выключен." << endl;
}

void Telefon::makeCall() {
    if (isPhoneTurnedOn) {
        isCurrentlyCalling = true;
        cout << "Идет звонок." << endl;
    } else {
        cout << "Телефон выключен." << endl;
    }
}

void Telefon::describe() {
    cout << "Телефон модели " << model << " оператора " << operatorName << ", уровень заряда батареи: " << batteryLevel << "%." << endl;
}