#ifndef RUCHKA_H
#define RUCHKA_H

#include <iostream>
#include <string>

using namespace std;

class GelievaiaRuchka {
private:
    string inkColor;
    string brand;
    bool isOpen;
    bool hasInk;
    int inkLevel; 

public:
    // геттеры
    string getInkColor() { return inkColor; }
    string getBrand() { return brand; }
    bool isOpen() { return isOpen; }
    bool hasInk() { return hasInk; }
    int getInkLevel() { return inkLevel; }

    // сеттеры
    void setInkColor(string newInkColor) { inkColor = newInkColor; }
    void setBrand(string newBrand) { brand = newBrand; }
    void setIsOpen(bool newIsOpen) { isOpen = newIsOpen; }
    void setHasInk(bool newHasInk) { hasInk = newHasInk; }
    void setInkLevel(int newInkLevel) { inkLevel = newInkLevel; }

    void open();
    void close();
    void write();
    void describe();
};

#endif