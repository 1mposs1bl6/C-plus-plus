#include "kupyura.h"

kupyura::kupyura() : kupyura(100, "гривна", true, true) {} 

kupyura::kupyura(int nominal, string currency, bool isWhole, bool isInCirculation) {
  this->nominal = nominal;
  this->currency = currency;
  this->isWhole = isWhole;
  this->isInCirculation = isInCirculation;
}

kupyura::kupyura(const kupyura& other) {
  this->nominal = other.nominal;
  this->currency = other.currency;
  this->isWhole = other.isWhole;
  this->isInCirculation = other.isInCirculation;
}

void kupyura::describe() {
  cout << "Купюра номиналом " << nominal << " " << currency << "." << endl;
}

bool kupyura::operator==(const kupyura& other) const {
  return (nominal == other.nominal && currency == other.currency);
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
  string currency;

  cout << "Введите номинал купюры: ";
  is >> nominal;
  cout << "Введите валюту: ";
  getline(is, currency);

  kupyura.setNominal(nominal);
  kupyura.setCurrency(currency);

  return is;
}