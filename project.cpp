#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void SetColor(int color) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, color);
}
void ClearScreen() {
  system("cls");
}

void ShowMenu() {
  ClearScreen();
  SetColor(11);
  cout << "   Змейка" << endl << endl;
  SetColor(10);
  cout << "1. Новая игра" << endl;
  cout << "2. Настройки" << endl;
  cout << "3. Выход" << endl << endl;
  SetColor(15);
  cout << "Выберите действие: ";
}
int GetMenuChoice() {
  int choice;
  cin >> choice;
  while (choice < 1 || choice > 3) {
  cout << "Неверный выбор. Попробуйте снова: ";
   cin >> choice;
  }
  return choice;
}

void NewGame() {
// делаю еще
}

void Settings() {
  ClearScreen();
  SetColor(10);
  cout << "Настройки игры:" << endl << endl;
  cout << "1. Изменить скорость" << endl;
  cout << "2. Изменить размер поля" << endl;
  cout << "3. Вернуться в главное меню" << endl << endl;
  SetColor(15);
  cout << "Выберите действие: ";
  int choice;
  cin >> choice;
  switch (choice) {
    case 1:
      cout << "Введите новую скорость (в миллисекундах): ";
      // делаю еще
      break;
    case 2:
      cout << "Введите новый размер поля (ширина, высота): ";
      // делаю еще
      break;
    case 3:
      break;
    default:
      cout << "Неверный выбор." << endl;
      break;
}
}
int main() {
  while (true) {
    ShowMenu();
    int choice = GetMenuChoice();
    switch (choice) {
      case 1:
        NewGame();
        break;
      case 2:
        Settings();
        break;
      case 3:
        return 0;
    }
  }
 return 0;
}