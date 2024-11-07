#include "chaynik.h"

chaynik::chaynik() : chaynik("пластик", 1) {}

chaynik::chaynik(string material, int volume) {
  this->material = material;
  this->volume = volume;
  this->isOn = false;
}

void chaynik::boil() {
  if (isOn) {
    cout << "чайник уже кипит!" << endl;
  } else {
    cout << "чайник закипает..." << endl;
    isOn = true; 
  }
}

void chaynik::pour() {
  if (isOn) {
    cout << "чайник кипит, будьте осторожны!" << endl;
  } else {
    cout << "чайник пуст." << endl;
  }
}

void chaynik::describe() {
  cout << "чайник из " << material << ", объемом " << volume << " литров." << endl;
  if (isOn) {
    cout << "чайник кипит!" << endl;
  }
}