#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

const char EMPTY_CELL = ' ';
const char SNAKE_CELL = 'O';
const char FOOD_CELL = 'X';

struct Snake {
  int x, y;
  int length;
};

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
  cout << "Змейка" << endl << endl;
  SetColor(10);
  cout << "1. Новая игра" << endl;
  cout << "2.Выход" << endl << endl;
  SetColor(15);
  cout << "Выберите действие:";
}
int GetMenuChoice() {
  int choice;
  cin >> choice;
  while (choice < 1 || choice > 2) {
    cout << "Неверный выбор.Попробуйте снова:";
    cin >> choice;
  }
  return choice;
}
void InitializeGame(Snake& snake, char field[][20], int width, int height) {
  snake.x = width / 2;
  snake.y = height / 2;
  snake.length = 1;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      field[i][j] = EMPTY_CELL;
    }
  }
  field[snake.y][snake.x] = SNAKE_CELL;
}
void GenerateFood(char field[][20], int width, int height) {
  int x, y;
  do {
    x = rand() % width;
    y = rand() % height;
  } while (field[y][x] != EMPTY_CELL);
  field[y][x] = FOOD_CELL;
}
void MoveSnake(Snake& snake, char field[][20], int width, int height, int direction) {
  int prevX = snake.x;
  int prevY = snake.y;
  switch (direction) {
    case 72://Вверх
      snake.y--;
      break;
    case 80: //Вниз
      snake.y++;
      break;
    case 75: //Влево
      snake.x--;
      break;
    case 77: //Вправо
      snake.x++;
      break;
  }

  if (snake.x < 0 || snake.x >= width || snake.y < 0 || snake.y >= height || field[snake.y][snake.x] == SNAKE_CELL) {
    return;
  }

  field[snake.y][snake.x] = SNAKE_CELL;

  for (int i = 0; i < snake.length; i++) {
    field[prevY][prevX] = (i == snake.length - 1) ? EMPTY_CELL : SNAKE_CELL;
    prevX = snake.x;
    prevY = snake.y;
    switch (direction) {
      case 72:
        prevY++;
        break;
      case 80:
        prevY--;
        break;
      case 75:
        prevX++;
        break;
      case 77:
        prevX--;
        break;
    }
  }
}
bool CheckCollision(Snake& snake, char field[][20], int width, int height) {
  if (snake.x < 0 || snake.x >= width || snake.y < 0 || snake.y >= height) {
    return true;
  }
  if (field[snake.y][snake.x] == SNAKE_CELL) {
    return true;
  }
  return false;


void DrawField(char field[][20], int width, int height) {
  ClearScreen();
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << field[i][j];
    }
    cout << endl;
  }
}
}
void NewGame() {
  int width = 20;
  int height = 10;
  int speed = 100;

  char field[20][20];

  Snake snake;
  InitializeGame(snake, field, width, height);

  GenerateFood(field, width, height);
  while (true) {
    DrawField(field, width, height);
    if (_kbhit()) {
      int key = _getch();
      MoveSnake(snake, field, width, height, key);
    }
    if (CheckCollision(snake, field, width, height)) {
      cout << "Игра окончена!" << endl;
      break;
  }
    Sleep(speed);
  }
}
int main() {
  srand(time(NULL));
  while (true) {
    ShowMenu();
    int choice = GetMenuChoice();
    switch (choice) {
      case 1:
        NewGame();
        break;
      case 2:
        return 0;
    }
  }
  return 0;
}
