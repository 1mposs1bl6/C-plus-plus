#ifndef KUPYURA_H
#define KUPYURA_H

#include <iostream>
#include <string>

using namespace std;

class Kupyura {
private:
    int nominal;
    string currency;
    bool isWhole;
    bool isInCirculation;

public:
    // геттеры
    int getNominal() { return nominal; }
    string getCurrency() { return currency; }
    bool isWhole() { return isWhole; }
    bool isInCirculation() { return isInCirculation; }

    // сеттеры
    void setNominal(int newNominal) { nominal = newNominal; }
    void setCurrency(string newCurrency) { currency = newCurrency; }
    void setIsWhole(bool newIsWhole) { isWhole = newIsWhole; }
    void setIsInCirculation(bool newIsInCirculation) { isInCirculation = newIsInCirculation; }

    void describe();
};

#endif