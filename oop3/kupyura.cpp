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