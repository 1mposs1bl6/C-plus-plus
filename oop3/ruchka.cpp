#include "ruchka.h"

void gelievaiaRuchka::open() {
  isOpen = true;
  cout << "Ручка открыта" << endl;
}

void gelievaiaRuchka::close() {
  isOpen = false;
  cout << "Ручка закрыта" << endl;
}

void gelievaiaRuchka::write() {
  if (isOpen && hasInk) {
    inkLevel--;
    cout << "Пишем" << endl;
  } else {
    cout << "Ручка не открыта или чернила закончились" << endl;
  }
}

void gelievaiaRuchka::describe() {
  cout << "ручка марки " << brand << ",цвет чернил: " << inkColor << ",остаток чернил: " << inkLevel << "%" << endl;
}