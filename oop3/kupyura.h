#ifndef KUPYURA_H
#define KUPYURA_H

#include <iostream>
#include <string>

using namespace std;

class kupyura {
private:
  int nominal;
  string currency;
  bool isWhole;
  bool isInCirculation;

public:
  int getNominal() { return nominal; }
  string getCurrency() { return currency; }
  bool isWhole() { return isWhole; }
  bool isInCirculation() { return isInCirculation; }

  void setNominal(int nominal) { this->nominal = nominal; }
  void setCurrency(string currency) { this->currency = currency; }
  void setIsWhole(bool isWhole) { this->isWhole = isWhole; }
  void setIsInCirculation(bool isInCirculation) { this->isInCirculation = isInCirculation; }

  void describe();
};

#endif