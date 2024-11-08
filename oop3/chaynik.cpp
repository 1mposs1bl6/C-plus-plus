#include "chaynik.h"

chaynik::chaynik() : chaynik("пластик", 1) {}

chaynik::chaynik(string material, int volume) {
  this->material = material;
  this->volume = volume;
  this->isOn = false;
}

chaynik::chaynik(const chaynik& other) {
  this->material = other.material;
  this->volume = other.volume;
  this->isOn = other.isOn;
}

void chaynik::boil() {
  if (isOn) {
    cout << "Чайник уже кипит!" << endl;
  } else {
    cout << "Чайник закипает..." << endl;
    isOn = true;
  }
}

void chaynik::pour() {
  if (isOn) {
    cout << "Чайник кипит, будь осторожен!" << endl;
  } else {
    cout << "Чайник пуст." << endl;
  }
}

void chaynik::describe() {
  cout << "Чайник из " << material << ", объемом " << volume << " литров." << endl;
  if (isOn) {
    cout << "Чайник кипит!" << endl;
  }
}