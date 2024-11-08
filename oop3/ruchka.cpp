#include "ruchka.h"

gelievaiaRuchka::gelievaiaRuchka() : gelievaiaRuchka("Черный", "Bic", 100) {}

gelievaiaRuchka::gelievaiaRuchka(string inkColor, string brand, int inkLevel) {
  this->inkColor = inkColor;
  this->brand = brand;
  this->inkLevel = inkLevel;
  isOpen = false;
  hasInk = true;
}

gelievaiaRuchka::gelievaiaRuchka(const gelievaiaRuchka& other) {
  this->inkColor = other.inkColor;
  this->brand = other.brand;
  this->inkLevel = other.inkLevel;
  this->isOpen = other.isOpen;
  this->hasInk = other.hasInk;
}

void gelievaiaRuchka::open() {
  isOpen = true;
  cout << "Ручка открыта!" << endl;
}

void gelievaiaRuchka::close() {
  isOpen = false;
  cout << "Ручка закрыта." << endl;
}

void gelievaiaRuchka::write() {
  if (isOpen && hasInk) {
    inkLevel--;
    cout << "Пишу..." << endl;
  } else {
    cout << "Ручка не открыта или чернила закончились." << endl;
  }
}

void gelievaiaRuchka::describe() {
  cout << "Ручка марки " << brand << ", цвет чернил: " << inkColor << ", уровень чернил: " << inkLevel << "%" << endl;
}