#include "telefon.h"

telefon::telefon() : telefon("iPhone", "Киевстар", 100) {} 

telefon::telefon(char* model, string operatorName, int batteryLevel) {
  this->model = new char[strlen(model) + 1];
  strcpy(this->model, model);
  this->operatorName = operatorName;
  this->batteryLevel = batteryLevel;
  this->isPhoneTurnedOn = false;
  this->isCurrentlyCalling = false;
}

telefon::telefon(const telefon& other) {
  this->model = new char[strlen(other.model) + 1];
  strcpy(this->model, other.model);
  this->operatorName = other.operatorName;
  this->batteryLevel = other.batteryLevel;
  this->isPhoneTurnedOn = other.isPhoneTurnedOn;
  this->isCurrentlyCalling = other.isCurrentlyCalling;
}

telefon::~telefon() {
  delete[] model;
}

void telefon::turnOn() {
  isPhoneTurnedOn = true;
  cout << "Телефон включен!" << endl;
}

void telefon::turnOff() {
  isPhoneTurnedOn = false;
  cout << "Телефон выключен." << endl;
}

void telefon::makeCall() {
  if (isPhoneTurnedOn) {
    isCurrentlyCalling = true;
    cout << "Звонок идет!" << endl;
  } else {
    cout << "Телефон выключен." << endl;
  }
}

void telefon::describe() {
  cout << "Модель: " << model << ", Оператор: " << operatorName << ", Батарея: " << batteryLevel << "%" << endl;
}

bool telefon::operator==(const telefon& other) const {
  return (strcmp(model, other.model) == 0 && operatorName == other.operatorName && batteryLevel == other.batteryLevel);
}

bool telefon::operator!=(const telefon& other) const {
  return !(*this == other);
}

bool telefon::operator>(const telefon& other) const {
  return (batteryLevel > other.batteryLevel);
}

bool telefon::operator<(const telefon& other) const {
  return (batteryLevel < other.batteryLevel);
}

ostream& operator<<(ostream& os, const telefon& telefon) {
  os << "Модель: " << telefon.getModel() << endl;
  os << "Оператор: " << telefon.getOperatorName() << endl;
  os << "Батарея: " << telefon.getBatteryLevel() << "%" << endl;
  return os;
}

istream& operator>>(istream& is, telefon& telefon) {
  char model[100];
  string operatorName;
  int batteryLevel;

  cout << "Введите модель телефона: ";
  is.getline(model, 100);
  cout << "Введите оператора: ";
  getline(is, operatorName);
  cout << "Введите уровень заряда батареи (%): ";
  is >> batteryLevel;

  telefon.setModel(model);
  telefon.setOperatorName(operatorName);
  telefon.setBatteryLevel(batteryLevel);

  return is;
}

char* telefon::getModel() const {
  return model; 
}

void telefon::setModel(const char* model) {
  delete[] this->model;
  this->model = new char[strlen(model) + 1];
  strcpy(this->model, model);
}