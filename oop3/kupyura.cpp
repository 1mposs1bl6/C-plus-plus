#include "kupyura.h"

kupyura::kupyura() : kupyura(500, "гривны", true, true) {}

kupyura::kupyura(int nominal, string currency, bool isWhole, bool isInCirculation) {
  this->nominal = nominal;
  this->currency = currency;
  this->isWhole = isWhole;
  this->isInCirculation = isInCirculation;
}

void kupyura::describe() {
  cout << "Купюра номиналом " << nominal << " " << currency << "." << endl;
}