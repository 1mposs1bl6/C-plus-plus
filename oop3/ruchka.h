#ifndef RUCHKA_H
#define RUCHKA_H

#include <iostream>
#include <string>

using namespace std;

class gelievaiaRuchka {
private:
  string inkColor;
  string brand;
  bool isOpen;
  bool hasInk;
  int inkLevel; 

public:
  string getInkColor() { return inkColor; }
  string getBrand() { return brand; }
  bool isOpen() { return isOpen; }
  bool hasInk() { return hasInk; }
  int getInkLevel() { return inkLevel; }

  void setInkColor(string inkColor) { this->inkColor = inkColor; }
  void setBrand(string brand) { this->brand = brand; }
  void setIsOpen(bool isOpen) { this->isOpen = isOpen; }
  void setHasInk(bool hasInk) { this->hasInk = hasInk; }
  void setInkLevel(int inkLevel) { this->inkLevel = inkLevel; }

  void open();
  void close();
  void write();
  void describe();
};

#endif