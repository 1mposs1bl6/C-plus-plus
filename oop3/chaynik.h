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

public:
  string getMaterial() { return material; }
  int getVolume() { return volume; }
  bool isOn() { return isOn; }

  void setMaterial(string material) { this->material = material; }
  void setVolume(int volume) { this->volume = volume; }
  void setIsOn(bool isOn) { this->isOn = isOn; }

  void boil();
  void pour();
  void describe();
};

#endif