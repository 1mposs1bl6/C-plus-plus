#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <deque>
#include <vector>
#include <cstdlib>
using namespace std;

const char EMPTY_CELL = ' '; // пустая клетка
const char SNAKE_BODY = 'o'; // тело змейки
const char SNAKE_HEAD = '0'; // голова змейки
const char FOOD_CELL = 'X'; // еда
const char WALL_CELL = '#'; // стена
const char BOMB_CELL = 'B'; // бомба

struct Position {
    int x, y; // координаты
};

struct Snake {
    deque<Position> segments; // части змейки
    int direction; // направление: 72 - вверх, 80 - вниз, 75 - влево, 77 - вправо
};

void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void ClearScreen() {
    system("cls"); // очищаем экран
}

void ShowMenu() {
    ClearScreen();
    SetColor(11); // синий для "змейка"
    cout << "              ***********************************************************************************\n";
    cout << "              *                                                                                 *\n";
    cout << "              *                                           ййййййййй                             *\n";
    cout << "              *                                                                                 *\n";
    cout << "              *     ззззз     мм         мм   ЕЕЕЕЕЕЕ   ййй         йй  кк   кк      АА         *\n";
    cout << "              *        ззз   мм мм     мм мм  ЕЕ        йй й        йй  кк   кк    АА  АА       *\n";
    cout << "              *         зз   мм   мм  мм  мм  ЕЕ        йй  йй      йй  кк  кк     АА  АА       *\n";
    cout << "              *      ззззз   мм     мм    мм  ЕЕЕЕЕЕЕ   йй    йй    йй  кккк     АА      АА     *\n";
    cout << "              *          зз  мм           мм  ЕЕ        йй      йй  йй  кк  кк   АААААААААА     *\n";
    cout << "              *         ззз  мм           мм  ЕЕ        йй        й йй  кк   кк  АА      АА     *\n";
    cout << "              *      ззззз   мм           мм  ЕЕЕЕЕЕЕ   йй         ййй  кк   кк  АА      АА     *\n";
    cout << "              *                                                                                 *\n";
    cout << "              ***********************************************************************************\n";

    SetColor(14); // желтый для "новая игра"
    cout << "                                          |       1. новая игра       |\n";
    cout << "                                          +---------------------------+\n";

    SetColor(10); // зеленый для "выход"
    cout << "                                          |       2. выход            |\n";
    cout << "                                          +---------------------------+\n";

    SetColor(15); // белый текст
    cout << "выберите действие: ";
}

int GetMenuChoice() {
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 2) {
        cout << "неверный выбор. попробуйте снова: ";
        cin >> choice;
    }
    return choice;
}

void ShowDifficultyMenu() {
    ClearScreen();
    SetColor(15); // белый текст
    cout << "выберите уровень сложности:\n";
    SetColor(14); // желтый для легкого
    cout << "1. легкий (2 бомбы)\n";
    SetColor(10); // зеленый для среднего
    cout << "2. средний (4 бомбы)\n";
    SetColor(12); // красный для тяжелого
    cout << "3. тяжелый (6 бомб)\n";
    SetColor(15); // белый текст
    cout << "выберите уровень: ";
}

int GetDifficultyChoice() {
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 3) {
        cout << "неверный выбор. попробуйте снова: ";
        cin >> choice;
    }
    return choice;
}

void InitializeGame(Snake& snake, char field[][22], int width, int height) {
    Position head;
    head.x = width / 2 + 1; // ставим голову по центру
    head.y = height / 2 + 1;
    snake.segments.push_back(head);
    snake.direction = 77; // изначально вправо

    // создаем поле
    for (int i = 0; i < height + 2; i++) {
        for (int j = 0; j < width + 2; j++) {
            if (i == 0 || i == height + 1 || j == 0 || j == width + 1)
                field[i][j] = WALL_CELL; // стены
            else
                field[i][j] = EMPTY_CELL; // пустота
        }
    }
    field[head.y][head.x] = SNAKE_HEAD; // устанавливаем голову змейки
}

void GenerateFood(char field[][22], int width, int height) {
    int x, y;
    do {
        x = rand() % width + 1; // генерируем координаты еды
        y = rand() % height + 1;
    } while (field[y][x] != EMPTY_CELL); // повторяем, если на месте еды не пусто
    field[y][x] = FOOD_CELL; // ставим еду
}

void GenerateBombs(char field[][22], int width, int height, int numBombs) {
    for (int i = 0; i < numBombs; i++) {
        int x, y;
        do {
            x = rand() % width + 1; // генерируем координаты бомбы
            y = rand() % height + 1;
        } while (field[y][x] != EMPTY_CELL); // повторяем, если на месте бомбы не пусто
        field[y][x] = BOMB_CELL; // ставим бомбу
    }
}

bool MoveSnake(Snake& snake, char field[][22], int width, int height) {
    Position currentHead = snake.segments.front();
    Position newHead = currentHead;

    // двигаем голову в зависимости от направления
    switch (snake.direction) {
    case 72: newHead.y--; break; // вверх
    case 80: newHead.y++; break; // вниз
    case 75: newHead.x--; break; // влево
    case 77: newHead.x++; break; // вправо
    }

    // проверяем столкновения
    if (field[newHead.y][newHead.x] == WALL_CELL || field[newHead.y][newHead.x] == SNAKE_BODY || field[newHead.y][newHead.x] == SNAKE_HEAD || field[newHead.y][newHead.x] == BOMB_CELL)
        return false; // если столкнулись, конец

    // проверяем, съели ли еду
    bool ateFood = false;
    if (field[newHead.y][newHead.x] == FOOD_CELL) {
        ateFood = true;
        GenerateFood(field, width, height); // генерируем новую еду
    }

    // перемещаем змейку
    field[currentHead.y][currentHead.x] = SNAKE_BODY; // превращаем старую голову в тело

    // добавляем новую голову
    snake.segments.push_front(newHead);
    field[newHead.y][newHead.x] = SNAKE_HEAD;

    if (!ateFood) {
        // убираем хвост, если не съели еду
        Position tail = snake.segments.back();
        field[tail.y][tail.x] = EMPTY_CELL;
        snake.segments.pop_back();
    }

    return true; // всё ок
}

void DrawField(char field[][22], int width, int height) {
    ClearScreen(); // очищаем экран
    for (int i = 0; i < height + 2; i++) {
        for (int j = 0; j < width + 2; j++) {
            // рисуем всё
            if (field[i][j] == WALL_CELL) {
                SetColor(10); // зеленая стена
                cout << WALL_CELL;
            }
            else if (field[i][j] == FOOD_CELL) {
                SetColor(12); // красная еда
                cout << FOOD_CELL;
            }
            else if (field[i][j] == BOMB_CELL) {
                SetColor(14); // желтая бомба
                cout << BOMB_CELL;
            }
            else {
                SetColor(15); // белый цвет для пустых клеток
                cout << field[i][j];
            }
        }
        cout << endl; // переход на следующую строку
    }
}

void NewGame(int numBombs) {
    int width = 20, height = 10, speed = 200;
    char field[12][22]; // поле
    Snake snake;
    InitializeGame(snake, field, width, height); // инициализация
    GenerateFood(field, width, height); // генерация еды
    GenerateBombs(field, width, height, numBombs); // генерация бомб

    bool gameOver = false; // игра еще не окончена
    while (!gameOver) {
        DrawField(field, width, height); // рисуем поле

        if (_kbhit()) { // если нажата клавиша
            int key = _getch();
            if (key == 0 || key == 224) {
                key = _getch(); // получаем код клавиши
                // изменяем направление
                if ((key == 72 && snake.direction != 80) ||
                    (key == 80 && snake.direction != 72) ||
                    (key == 75 && snake.direction != 77) ||
                    (key == 77 && snake.direction != 75))
                    snake.direction = key;
            }
        }

        if (!MoveSnake(snake, field, width, height)) { // двигаем змейку
            DrawField(field, width, height);
            // проверяем, проиграли ли
            if (field[snake.segments.front().y][snake.segments.front().x] == BOMB_CELL) {
                cout << "игра окончена! вы дотронулись до бомбы!" << endl;
            }
            else {
                cout << "игра окончена! ваш счёт: " << snake.segments.size() - 1 << endl;
            }
            gameOver = true;
        }

        Sleep(speed); // пауза перед следующим ходом
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); // инициализация генератора случайных чисел
    ShowMenu(); // показываем меню
    int menuChoice = GetMenuChoice(); // получаем выбор

    if (menuChoice == 1) { // новая игра
        ShowDifficultyMenu(); // показываем меню сложности
        int difficultyChoice = GetDifficultyChoice(); // получаем уровень сложности
        int numBombs = difficultyChoice + 1; // определяем количество бомб

        NewGame(numBombs); // начинаем новую игру
    }
    return 0; // конец программы
}
