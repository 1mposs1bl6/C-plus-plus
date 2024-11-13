#ifndef RUCHKA_H
#define RUCHKA_H

#include <iostream>
#include <string>

using namespace std;

class gelievaiaRuchka {
private:
  char* inkColor;
  string brand;
  bool isOpen;
  bool hasInk;
  int inkLevel; 

public:
  gelievaiaRuchka();
  gelievaiaRuchka(char* inkColor, string brand, bool hasInk, int inkLevel);
  gelievaiaRuchka(const gelievaiaRuchka& other);
  ~gelievaiaRuchka();

  char* getInkColor() const;
  string getBrand() { return brand; }
  bool isOpen() { return isOpen; }
  bool hasInk() { return hasInk; }
  int getInkLevel() { return inkLevel; }

  void setInkColor(const char* inkColor);
  void setBrand(string brand) { this->brand = brand; }
  void setIsOpen(bool isOpen) { this->isOpen = isOpen; }
  void setHasInk(bool hasInk) { this->hasInk = hasInk; }
  void setInkLevel(int inkLevel) { this->inkLevel = inkLevel; }

  void open();
  void close();
  void write();
  void describe();

  bool operator==(const gelievaiaRuchka& other) const;
  bool operator!=(const gelievaiaRuchka& other) const;
  bool operator>(const gelievaiaRuchka& other) const;
  bool operator<(const gelievaiaRuchka& other) const;
  friend ostream& operator<<(ostream& os, const gelievaiaRuchka& ruchka);
  friend istream& operator>>(istream& is, gelievaiaRuchka& ruchka);
};

#endif