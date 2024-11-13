#ifndef CHAYNIK_H
#define CHAYNIK_H

#include <iostream>
#include <string>

using namespace std;

class chaynik {
private:
  string material; 
  int volume;
  bool isOn;  
  char* brand;

public:
  chaynik();
  chaynik(string material, int volume);
  chaynik(const chaynik& other);
  ~chaynik();

  string getMaterial() { return material; }
  int getVolume() { return volume; }
  bool isOn() { return isOn; }
  char* getBrand() const;

  void setMaterial(string material) { this->material = material; }
  void setVolume(int volume) { this->volume = volume; }
  void setIsOn(bool isOn) { this->isOn = isOn; }
  void setBrand(const char* brand);

  void boil();
  void pour();
  void describe();

  bool operator==(const chaynik& other) const;
  bool operator!=(const chaynik& other) const;
  bool operator>(const chaynik& other) const;
  bool operator<(const chaynik& other) const;
  friend ostream& operator<<(ostream& os, const chaynik& chaynik);
  friend istream& operator>>(istream& is, chaynik& chaynik);
};

#endif