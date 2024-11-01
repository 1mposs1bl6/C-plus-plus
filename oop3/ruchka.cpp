#include "ruchka.h"

void GelievaiaRuchka::open() {
    isOpen = true;
    cout << "Ручка открыта" << endl;
}

void GelievaiaRuchka::close() {
    isOpen = false;
    cout << "Ручка закрыта" << endl;
}

void GelievaiaRuchka::write() {
    if (isOpen && hasInk) {
        inkLevel--;
        cout << "Пишем" << endl;
    } else {
        cout << "Ручка не открыта или чернила закончились" << endl;
    }
}

void GelievaiaRuchka::describe() {
    cout << "ручка марки " << brand << ",цвет чернил: " << inkColor << ",остаток чернил: " << inkLevel << "%" << endl;
}