#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void SetCursor(int x, int y, int color) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cord = { x, y };
  SetConsoleCursorPosition(hConsole, cord);
  SetConsoleTextAttribute(hConsole, color);
}


void Line(int length, char symbol, int color, bool isHorizontal) {
  SetCursor(0, 0, color);
  if (isHorizontal) {
    for (int i = 0; i < length; i++) {
      cout << symbol;
    }
  } else {
    for (int i = 0; i < length; i++) {
      cout << symbol << "/n";
   }
 }
}

void Rectangle(int width, int height, char frameSymbol, char fillSymbol, int frameColor, int fillColor, int x = 0, int y = 0) {
}

int Cube(int num) {
  return num * num * num;
}
int main() {
}