#include <iostream>
#include <string>
using namespace std;

struct Book {
  string title;
  string author;
  int pages;
  int year;
  string genre;
};
struct Phone {
  string brand;
  string model;
  int storage;
  double screenSize;
  int batteryCapacity;
};
struct Car {
  string brand;
  string model;
  int year;
  string engineType;
  int mileage;
};

int main() {
  //книга
  Book book1;
  book1.title = "Властелин колец";
  book1.author = "Джон Р. Р.Толкин";
  book1.pages = 1216;
  book1.year = 1954;
  book1.genre = "Фентези";

cout << "Книга:\n";
  cout << "Название: " << book1.title << "\n";
  cout << "Автор: " << book1.author << "\n";
  cout << "Количество страниц: " << book1.pages << "\n";
  cout << "Год издания: " << book1.year << "\n";
  cout << "Жанр:" << book1.genre << "\n\n";

  //телефон
  Phone phone1;
  phone1.brand = "Apple";
  phone1.model = "iPhone 13 Pro";
  phone1.storage = 256;
  phone1.screenSize = 6.1;
  phone1.batteryCapacity = 3095;

  cout << "Телефон:\n";
  cout << "Марка:" << phone1.brand << "\n";
  cout << "Модель: " << phone1.model << "\n";
  cout << "Объем памяти: " << phone1.storage << " ГБ\n";
  cout << "Диагональ экрана " << phone1.screenSize << " дюймов\n";
  cout << "Емкость батареи: " << phone1.batteryCapacity << " мАч\n\n";
  //машина
  Car car1;
  car1.brand = "Toyota";
  car1.model = "Camry";
  car1.year = 2022;
  car1.engineType = "Бензиновый";
  car1.mileage = 10000;
  cout << "Автомобиль:\n";
  cout << "Марка: " << car1.brand << "\n";
  cout << "Модель: " << car1.model << "\n";
  cout << "Год выпуска: " << car1.year << "\n";
  cout << "Тип двигателя:" << car1.engineType << "\n";
  cout << "Пробег: " << car1.mileage << " км\n";

return 0;
}