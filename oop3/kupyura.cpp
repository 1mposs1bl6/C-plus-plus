#include "kupyura.h"

kupyura::kupyura() : kupyura(100, "гривна", true, true) {} 

kupyura::kupyura(int nominal, char* currency, bool isWhole, bool isInCirculation) {
  this->nominal = nominal;
  this->currency = new char[strlen(currency) + 1];
  strcpy(this->currency, currency);
  this->isWhole = isWhole;
  this->isInCirculation = isInCirculation;
}

kupyura::kupyura(const kupyura& other) {
  this->nominal = other.nominal;
  this->currency = new char[strlen(other.currency) + 1];
  strcpy(this->currency, other.currency);
  this->isWhole = other.isWhole;
  this->isInCirculation = other.isInCirculation;
}

kupyura::~kupyura() {
  delete[] currency;
}

void kupyura::describe() {
  cout << "Купюра номиналом " << nominal << " " << currency << "." << endl;
}

bool kupyura::operator==(const kupyura& other) const {
  return (nominal == other.nominal && strcmp(currency, other.currency) == 0);
}

bool kupyura::operator!=(const kupyura& other) const {
  return !(*this == other);
}

bool kupyura::operator>(const kupyura& other) const {
  return (nominal > other.nominal);
}

bool kupyura::operator<(const kupyura& other) const {
  return (nominal < other.nominal);
}

ostream& operator<<(ostream& os, const kupyura& kupyura) {
  os << "Номинал: " << kupyura.getNominal() << endl;
  os << "Валюта: " << kupyura.getCurrency() << endl;
  return os;
}

istream& operator>>(istream& is, kupyura& kupyura) {
  int nominal;
  char currency[100];

  cout << "Введите номинал купюры: ";
  is >> nominal;
  cout << "Введите валюту: ";
  is.getline(currency, 100);

  kupyura.setNominal(nominal);
  kupyura.setCurrency(currency);

  return is;
}

char* kupyura::getCurrency() const {
  return currency; 
}

void kupyura::setCurrency(const char* currency) {
  delete[] this->currency;
  this->currency = new char[strlen(currency) + 1];
  strcpy(this->currency, currency);
}