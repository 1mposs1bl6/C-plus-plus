#include "chaynik.h"

chaynik::chaynik() : chaynik("пластик", 1) {}

chaynik::chaynik(string material, int volume) {
  this->material = material;
  this->volume = volume;
  this->isOn = false;
  this->brand = new char[10];
  strcpy(this->brand, "No brand");
}

chaynik::chaynik(const chaynik& other) {
  this->material = other.material;
  this->volume = other.volume;
  this->isOn = other.isOn;
  this->brand = new char[strlen(other.brand) + 1];
  strcpy(this->brand, other.brand);
}

chaynik::~chaynik() {
  delete[] brand;
}

void chaynik::boil() {
  if (isOn) {
    cout << "Чайник уже кипит!" << endl;
  } else {
    cout << "Чайник закипает..." << endl;
    isOn = true;
  }
}

void chaynik::pour() {
  if (isOn) {
    cout << "Чайник кипит, будь осторожен!" << endl;
  } else {
    cout << "Чайник пуст." << endl;
  }
}

void chaynik::describe() {
  cout << "Чайник из " << material << ", объемом " << volume << " литра." << endl;
  cout << "Бренд: " << brand << endl;
}

bool chaynik::operator==(const chaynik& other) const {
  return (material == other.material && volume == other.volume && strcmp(brand, other.brand) == 0); 
}

bool chaynik::operator!=(const chaynik& other) const {
  return !(*this == other);
}

bool chaynik::operator>(const chaynik& other) const {
  return (volume > other.volume);
}

bool chaynik::operator<(const chaynik& other) const {
  return (volume < other.volume);
}

ostream& operator<<(ostream& os, const chaynik& chaynik) {
  os << "Материал: " << chaynik.getMaterial() << endl;
  os << "Объем: " << chaynik.getVolume() << " литра" << endl;
  os << "Бренд: " << chaynik.getBrand() << endl; 
  return os;
}

istream& operator>>(istream& is, chaynik& chaynik) {
  string material;
  int volume;
  char brand[10];

  cout << "Введите материал чайника: ";
  getline(is, material);
  cout << "Введите объем чайника (в литрах): ";
  is >> volume;
  cout << "Введите бренд чайника: ";
  is >> brand;

  chaynik.setMaterial(material);
  chaynik.setVolume(volume);
  chaynik.setBrand(brand);

  return is;
}

char* chaynik::getBrand() const {
  return brand; 
}

void chaynik::setBrand(const char* brand) {
  delete[] this->brand;
  this->brand = new char[strlen(brand) + 1];
  strcpy(this->brand, brand);
}