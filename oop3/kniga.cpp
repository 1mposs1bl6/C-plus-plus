#include "kniga.h"

kniga::kniga() : kniga("Название книги", "Автор", 100) {}

kniga::kniga(string name, string author, int numberOfPages) {
  this->name = name;
  this->author = author;
  this->numberOfPages = numberOfPages;
  this->isOpen = false;
  this->currentPage = 0;
}

void kniga::open() {
  isOpen = true;
  cout << "Книга открыта" << endl;
}

void kniga::close() {
  isOpen = false;
  cout << "Книга закрыта" << endl;
}

void kniga::turnPage() {
  if (isOpen) {
    currentPage++;
    cout << "Страница перевернута" << endl;
  } else {
    cout << "Книга закрыта" << endl;
  }
}

void kniga::describe() {
  cout << "Книга " << name << " автора " << author << ", количество страниц: " << numberOfPages << "." << endl;
}