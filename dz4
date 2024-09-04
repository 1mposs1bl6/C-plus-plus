//Задание 1

#include <iostream>

int main() {
    int number;
    std::cout << "Введите целое число: ";
    std::cin >> number;

    std::cout << "Числа, на которые " << number << " делится без остатка: ";
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";

    return 0;
}

//Задание 2

#include <iostream>

int main() {
    int low = 0;
    int high = 1000;
    int attempts = 0;
    std::string response;

    std::cout << "Загадайте число от 0 до 1000, и я попробую его отгадать.\n";

    while (low <= high) {
        int mid = (low + high) / 2;
        attempts++;

        std::cout << "Ваше число " << mid << "? Введите 'больше', 'меньше' или 'да': ";
        std::cin >> response;

        if (response == "да") {
            std::cout << "Я угадал число " << mid << " за " << attempts << " попыток!\n";
            break;
        } else if (response == "больше") {
            low = mid + 1;
        } else if (response == "меньше") {
            high = mid - 1;
        } else {
            std::cout << "Введите корректный ответ.\n";
        }
    }

    return 0;
}

//Задание 3

#include <iostream>
#include <cmath>

int main() {
    double N, M;
    std::cout << "Введите сумму стипендии в месяц (грн): ";
    std::cin >> N;
    std::cout << "Введите расходы на проживание в месяц (грн): ";
    std::cin >> M;

    double total_expenses = 0;

    for (int month = 1; month <= 10; month++) {
        total_expenses += M;
        M *= 1.03;  // Увеличение расходов на 3% каждый месяц
    }

    double money_needed = total_expenses - 10 * N;
    std::cout << "Необходимо попросить у родителей " << money_needed << " грн на учебный год.\n";

    return 0;
}

//Задание 4

#include <iostream>
#include <iomanip>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void printCalendar(int year) {
    const std::string months[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
                                  "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int days;
    int currentDay = 1;

    // Учитываем високосный год
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    // Определение первого дня года (используем метод Зеллера)
    int dayCode;
    int d = 1, m = 1, y = year;
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    dayCode = (d + 2*m + (3*(m+1))/5 + y + y/4 - y/100 + y/400) % 7;

    // Печать календаря
    for (int month = 0; month < 12; month++) {
        std::cout << "  ------------ " << months[month] << " -------------\n";
        std::cout << "  Пн  Вт  Ср  Чт  Пт  Сб  Вс\n";

        // Выравнивание начала месяца
        for (int space = 1; space <= dayCode; space++) {
            std::cout << "     ";
        }

        // Печать дней месяца
        days = daysInMonth[month];
        for (int day = 1; day <= days; day++) {
            std::cout << std::setw(4) << day;
            if (++dayCode > 6) {
                dayCode = 0;
                std::cout << "\n";
            }
        }
        if (dayCode) {
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

int main() {
    int year;
    std::cout << "Введите год: ";
    std::cin >> year;

    printCalendar(year);

    return 0;
}
