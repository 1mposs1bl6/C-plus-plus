#ifndef KUPYURA_H
#define KUPYURA_H

#include <iostream>
#include <string>

using namespace std;

class kupyura {
private:
  int nominal;
  char* currency;
  bool isWhole;
  bool isInCirculation;

public:
  kupyura();
  kupyura(int nominal, char* currency, bool isWhole, bool isInCirculation);
  kupyura(const kupyura& other);
  ~kupyura();

  int getNominal() { return nominal; }
  char* getCurrency() const;
  bool isWhole() { return isWhole; }
  bool isInCirculation() { return isInCirculation; }

  void setNominal(int nominal) { this->nominal = nominal; }
  void setCurrency(const char* currency);
  void setIsWhole(bool isWhole) { this->isWhole = isWhole; }
  void setIsInCirculation(bool isInCirculation) { this->isInCirculation = isInCirculation; }

  void describe();

  bool operator==(const kupyura& other) const;
  bool operator!=(const kupyura& other) const;
  bool operator>(const kupyura& other) const;
  bool operator<(const kupyura& other) const;
  friend ostream& operator<<(ostream& os, const kupyura& kupyura);
  friend istream& operator>>(istream& is, kupyura& kupyura);
};

#endif