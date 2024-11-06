#include "kniga.h"

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