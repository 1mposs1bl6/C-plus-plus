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

bool gelievaiaRuchka::operator==(const gelievaiaRuchka& other) const {
  return (inkColor == other.inkColor && brand == other.brand && inkLevel == other.inkLevel);
}

bool gelievaiaRuchka::operator!=(const gelievaiaRuchka& other) const {
  return !(*this == other);
}

bool gelievaiaRuchka::operator>(const gelievaiaRuchka& other) const {
  return (inkLevel > other.inkLevel);
}

bool gelievaiaRuchka::operator<(const gelievaiaRuchka& other) const {
  return (inkLevel < other.inkLevel);
}

ostream& operator<<(ostream& os, const gelievaiaRuchka& ruchka) {
  os << "Марка: " << ruchka.getBrand() << endl;
  os << "Цвет чернил: " << ruchka.getInkColor() << endl;
  os << "Уровень чернил: " << ruchka.getInkLevel() << "%" << endl;
  return os;
}

istream& operator>>(istream& is, gelievaiaRuchka& ruchka) {
  string inkColor, brand;
  int inkLevel;

  cout << "Введите цвет чернил: ";
  getline(is, inkColor);
  cout << "Введите марку ручки: ";
  getline(is, brand);
  cout << "Введите уровень чернил: ";
  is >> inkLevel;

  ruchka.setInkColor(inkColor);
  ruchka.setBrand(brand);
  ruchka.setInkLevel(inkLevel);

  return is;
}