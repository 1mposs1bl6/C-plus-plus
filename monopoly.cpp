#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// Структура для представления игрока
struct Player {
    string name;
    int balance;
    int position;
    vector<int> properties;
};

// Структура для представления свойства
struct Property {
    string name;
    int price;
    int rent;
    bool owned;
    int owner; // Индекс игрока, владеющего свойством
};

// Функция для броска костей
int rollDice() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 6);
    return distrib(gen);
}

// Функция для проверки, является ли свойство доступным для покупки
bool isPropertyAvailable(vector<Property>& properties, int propertyIndex) {
    return !properties[propertyIndex].owned;
}

// Функция для покупки свойства
void buyProperty(vector<Property>& properties, Player& player, int propertyIndex) {
    if (isPropertyAvailable(properties, propertyIndex) && player.balance >= properties[propertyIndex].price) {
        player.balance -= properties[propertyIndex].price;
        properties[propertyIndex].owned = true;
        properties[propertyIndex].owner = player.position;
        player.properties.push_back(propertyIndex);
        cout << player.name << " купил " << properties[propertyIndex].name << endl;
    } else {
        cout << "Недостаточно средств для покупки." << endl;
    }
}

// Функция для оплаты аренды
void payRent(vector<Property>& properties, Player& payer, Player& receiver, int propertyIndex) {
    if (properties[propertyIndex].owned && properties[propertyIndex].owner != payer.position) {
        payer.balance -= properties[propertyIndex].rent;
        receiver.balance += properties[propertyIndex].rent;
        cout << payer.name << " заплатил " << receiver.name << " " << properties[propertyIndex].rent << " за аренду " << properties[propertyIndex].name << endl;
    }
}

int main() {
    srand(time(0));

    // Игроки
    vector<Player> players = {
        {"Игрок 1", 1500, 0, {}},
        {"Игрок 2", 1500, 0, {}},
    };

    // Ввод никнеймов
    cout << "Введите никнейм для Игрока 1: ";
    string nickname1;
    cin >> nickname1;
    players[0].name = nickname1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Введите никнейм для Игрока 2: ";
    string nickname2;
    cin >> nickname2;
    players[1].name = nickname2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Свойства
    vector<Property> properties = {
        {"Mediterranean Avenue", 60, 2, false, -1},
        {"Baltic Avenue", 60, 4, false, -1},
        {"Oriental Avenue", 100, 6, false, -1},
        {"Vermont Avenue", 100, 8, false, -1},
        {"Connecticut Avenue", 120, 10, false, -1},
        {"St. Charles Place", 140, 12, false, -1},
        {"States Avenue", 140, 14, false, -1},
        {"Virginia Avenue", 160, 16, false, -1},
        {"St. James Place", 180, 18, false, -1},
        {"Tennessee Avenue", 180, 20, false, -1},
        {"New York Avenue", 200, 22, false, -1},
        {"Kentucky Avenue", 220, 24, false, -1},
        {"Indiana Avenue", 220, 26, false, -1},
        {"Illinois Avenue", 240, 28, false, -1},
        {"Atlantic Avenue", 260, 30, false, -1},
        {"Ventnor Avenue", 260, 32, false, -1},
        {"Marvin Gardens", 280, 35, false, -1},
        {"Pacific Avenue", 300, 35, false, -1},
        {"North Carolina Avenue", 300, 40, false, -1},
        {"Pennsylvania Avenue", 320, 45, false, -1},
        {"Park Place", 350, 50, false, -1},
        {"Boardwalk", 400, 55, false, -1},
        {"Тюрьма", 0, 0, false, -1}, // Добавление тюрьмы
    };

    // Основной цикл игры
    while (true) {
        for (int i = 0; i < players.size(); i++) {
            if (players[i].balance > 0) {
                cout << "\nХодит " << players[i].name << endl;
                cout << "Ваш баланс: " << players[i].balance << endl;

                // Выбор способа броска
                cout << "Как вы хотите бросить кости? (рука/кинуть)" << endl;
                string choice;
                cin >> choice;

                int diceRoll;
                if (choice == "рука") {
                    // Бросок костей в руке
                    cout << "Введите результат броска (от 2 до 12): " << endl;
                    cin >> diceRoll;
                    while (diceRoll < 2 || diceRoll > 12) {
                        cout << "Некорректный результат. Введите результат от 2 до 12: " << endl;
                        cin >> diceRoll;
                    }
                } else if (choice == "кинуть") {
                    // Бросок костей
                    diceRoll = rollDice();
                    cout << "Бросок: " << diceRoll << endl;
                } else {
                    cout << "Неверный выбор." << endl;
                    continue;
                }

                // Перемещение игрока
                players[i].position = (players[i].position + diceRoll) % properties.size();

                // Проверка, попал ли игрок на Тюрьму
                if (properties[players[i].position].name == "Тюрьма") {
                    cout << players[i].name << " попал в тюрьму!" << endl;
                    cout << "Пропустите ход." << endl;
                    continue;
                }

                // Проверка, попал ли игрок на свойство
                if (isPropertyAvailable(properties, players[i].position)) {
                    // Предложение покупки
                    cout << "Вы попали на " << properties[players[i].position].name << ". Купить за " << properties[players[i].position].price << " $? (да/нет)" << endl;
                    string answer;
                    cin >> answer;
                    if (answer == "да") {
                        buyProperty(properties, players[i], players[i].position);
                    }
                } else {
                    // Оплата аренды
                    payRent(properties, players[i], players[properties[players[i].position].owner], players[i].position);
                }

                // Проверка на банкротство
                if (players[i].balance <= 0) {
                    cout << players[i].name << " обанкротился!" << endl;
                    // Удаление игрока из игры
                    players.erase(players.begin() + i);
                    // Перенос собственности обанкротившегося игрока
                    for (int propertyIndex : players[i].properties) {
                        properties[propertyIndex].owned = false;
                        properties[propertyIndex].owner = -1;
                    }
                }

                // Проверка окончания игры
                if (players.size() == 1) {
                    cout << "\nИгра окончена! Победил " << players[0].name << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}