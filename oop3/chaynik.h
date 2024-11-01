#ifndef CHAYNIK_H
#define CHAYNIK_H

#include <iostream>
#include <string>

using namespace std;

class Chaynik {
private:
    string brand;
    int power;
    double volume;
    bool isOn;
    bool isBoiling;

public:
    // геттеры
    string getBrand() { return brand; }
    int getPower() { return power; }
    double getVolume() { return volume; }
    bool isOn() { return isOn; }
    bool isBoiling() { return isBoiling; }

    // сеттеры
    void setBrand(string newBrand) { brand = newBrand; }
    void setPower(int newPower) { power = newPower; }
    void setVolume(double newVolume) { volume = newVolume; }
    void setIsOn(bool newIsOn) { isOn = newIsOn; }
    void setIsBoiling(bool newIsBoiling) { isBoiling = newIsBoiling; }

    void turnOn();
    void turnOff();
    void heatUp();
    void pourWater();
    void describe();
};

#endif