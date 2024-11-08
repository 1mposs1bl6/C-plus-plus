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