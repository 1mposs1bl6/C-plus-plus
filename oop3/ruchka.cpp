#include "ruchka.h"

gelievaiaRuchka::gelievaiaRuchka() : gelievaiaRuchka("Черный", "Bic", 100) {}

gelievaiaRuchka::gelievaiaRuchka(char* inkColor, string brand, int inkLevel) {
  this->inkColor = new char[strlen(inkColor) + 1];
  strcpy(this->inkColor, inkColor);
  this->brand = brand;
  this->inkLevel = inkLevel;
  isOpen = false;
  hasInk = true;
}

gelievaiaRuchka::gelievaiaRuchka(const gelievaiaRuchka& other) {
  this->inkColor = new char[strlen(other.inkColor) + 1];
  strcpy(this->inkColor, other.inkColor);
  this->brand = other.brand;
  this->inkLevel = other.inkLevel;
  this->isOpen = other.isOpen;
  this->hasInk = other.hasInk;
}

gelievaiaRuchka::~gelievaiaRuchka() {
  delete[] inkColor;
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
  return (strcmp(inkColor, other.inkColor) == 0 && brand == other.brand && inkLevel == other.inkLevel);
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
  char inkColor[100];
  string brand;
  int inkLevel;

  cout << "Введите цвет чернил: ";
  is.getline(inkColor, 100);
  cout << "Введите марку ручки: ";
  getline(is, brand);
  cout << "Введите уровень чернил: ";
  is >> inkLevel;

  ruchka.setInkColor(inkColor);
  ruchka.setBrand(brand);
  ruchka.setInkLevel(inkLevel);

  return is;
}

char* gelievaiaRuchka::getInkColor() const {
  return inkColor; 
}

void gelievaiaRuchka::setInkColor(const char* inkColor) {
  delete[] this->inkColor;
  this->inkColor = new char[strlen(inkColor) + 1];
  strcpy(this->inkColor, inkColor);
}