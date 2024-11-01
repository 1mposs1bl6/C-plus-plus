#include "kniga.h"

void Kniga::open() {
    isOpen = true;
    cout << "Книга открыта" << endl;
}

void Kniga::close() {
    isOpen = false;
    cout << "Книга закрыта" << endl;
}

void Kniga::turnPage() {
    if (isOpen) {
        currentPage++;
        cout << "Страница перевернута" << endl;
    } else {
        cout << "Книга закрыта" << endl;
    }
}

void Kniga::describe() {
    cout << "Книга " << name << " автора " << author << ", количество страниц: " << numberOfPages << "." << endl;
}