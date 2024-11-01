#include "chaynik.h"

void Chaynik::turnOn() {
    isOn = true;
    cout << "чайник включен" << endl;
}

void Chaynik::turnOff() {
    isOn = false;
    cout << "чайник выключен" << endl;
}

void Chaynik::heatUp() {
    if (isOn) {
        isBoiling = true;
        cout << "вода закипела" << endl;
    } else {
        cout << "чайник не включен" << endl;
    }
}

void Chaynik::pourWater() {
    cout << "вода налита в чайник" << endl;
}

void Chaynik::describe() {
    cout << "чайник марки " << brand << " с мощностью " << power << " вт, объемом " << volume << " литров" << endl;
}