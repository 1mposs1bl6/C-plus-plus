#include "kniga.h"

kniga::kniga() : kniga("Название книги", "Автор", 100) {} 

kniga::kniga(string name, string author, int numberOfPages) {
  this->name = name;
  this->author = author;
  this->numberOfPages = numberOfPages;
  isOpen = false;
  currentPage = 0;
}

kniga::kniga(const kniga& other) {
  this->name = other.name;
  this->author = other.author;
  this->numberOfPages = other.numberOfPages;
  this->isOpen = other.isOpen;
  this->currentPage = other.currentPage;
}

void kniga::open() {
  isOpen = true;
  cout << "Книга открыта!" << endl;
}

void kniga::close() {
  isOpen = false;
  cout << "Книга закрыта." << endl;
}

void kniga::turnPage() {
  if (isOpen) {
    currentPage++;
    cout << "Страница перевернута!" << endl;
  } else {
    cout << "Книга закрыта." << endl;
  }
}

void kniga::describe() {
  cout << "Книга " << name << " автора " << author << ", всего страниц: " << numberOfPages << "." << endl;
}

bool kniga::operator==(const kniga& other) const {
  return (name == other.name && author == other.author && numberOfPages == other.numberOfPages);
}

bool kniga::operator!=(const kniga& other) const {
  return !(*this == other);
}

bool kniga::operator>(const kniga& other) const {
  return (numberOfPages > other.numberOfPages);
}

bool kniga::operator<(const kniga& other) const {
  return (numberOfPages < other.numberOfPages);
}

ostream& operator<<(ostream& os, const kniga& kniga) {
  os << "Название: " << kniga.getName() << endl;
  os << "Автор: " << kniga.getAuthor() << endl;
  os << "Количество страниц: " << kniga.getNumberOfPages() << endl;
  return os;
}

istream& operator>>(istream& is, kniga& kniga) {
  string name, author;
  int numberOfPages;

  cout << "Введите название книги: ";
  getline(is, name);
  cout << "Введите автора: ";
  getline(is, author);
  cout << "Введите количество страниц: ";
  is >> numberOfPages;

  kniga.setName(name);
  kniga.setAuthor(author);
  kniga.setNumberOfPages(numberOfPages);

  return is;
}