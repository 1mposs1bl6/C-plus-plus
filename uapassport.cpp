#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Класс для представления визы
class Visa {
private:
    string country;
    string type;
    string dateIssued;
    string dateExpiration;

public:
    Visa(const string& country, const string& type, const string& dateIssued, const string& dateExpiration)
        : country(country), type(type), dateIssued(dateIssued), dateExpiration(dateExpiration) {}

    // Геттеры
    string getCountry() const { return country; }
    string getType() const { return type; }
    string getDateIssued() const { return dateIssued; }
    string getDateExpiration() const { return dateExpiration; }
};

// Класс для представления паспорта
class Passport {
protected:
    string lastName;
    string firstName;
    string patronymic;
    string series;
    string number;
    string dateIssued;
    string dateExpiration;

public:
    Passport(const string& lastName, const string& firstName, const string& patronymic, const string& series,
             const string& number, const string& dateIssued, const string& dateExpiration)
        : lastName(lastName), firstName(firstName), patronymic(patronymic), series(series), number(number),
          dateIssued(dateIssued), dateExpiration(dateExpiration) {}

    // Геттеры
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getPatronymic() const { return patronymic; }
    string getSeries() const { return series; }
    string getNumber() const { return number; }
    string getDateIssued() const { return dateIssued; }
    string getDateExpiration() const { return dateExpiration; }

    // Вывод информации о паспорте
    void print() const {
        cout << "Фамилия: " << lastName << endl;
        cout << "Имя: " << firstName << endl;
        cout << "Отчество: " << patronymic << endl;
        cout << "Серия: " << series << endl;
        cout << "Номер: " << number << endl;
        cout << "Дата выдачи: " << dateIssued << endl;
        cout << "Дата окончания действия: " << dateExpiration << endl;
    }
};

// Класс для представления заграничного паспорта
class ForeignPassport : public Passport {
private:
    vector<Visa> visas;

public:
    ForeignPassport(const string& lastName, const string& firstName, const string& patronymic, const string& series,
                    const string& number, const string& dateIssued, const string& dateExpiration)
        : Passport(lastName, firstName, patronymic, series, number, dateIssued, dateExpiration) {}

    // Добавление визы
    void addVisa(const Visa& visa) {
        visas.push_back(visa);
    }

    // Вывод информации о загран.паспорте, включая визы
    void print() const {
        Passport::print(); 

        cout << "Визы:" << endl;
        for (const auto& visa : visas) {
            cout << "  Страна: " << visa.getCountry() << endl;
            cout << "  Тип: " << visa.getType() << endl;
            cout << "  Дата выдачи: " << visa.getDateIssued() << endl;
            cout << "  Дата окончания действия: " << visa.getDateExpiration() << endl;
        }
    }
};

int main() {
    // Создание паспорта Алексея
    Passport alexPassport("Бабурин", "Алексей", "Иванович", "АА", "123456", "01.01.2020", "01.01.2030");

    // Создание паспорта Никиты
    Passport nikitaPassport("Горбачёв", "Никита", "Алексеевич", "BB", "789012", "01.02.2021", "01.02.2031");

    // Создание заграничного паспорта Никиты
    ForeignPassport foreignPassport("Горбачёв", "Никита", "Алексеевич", "BB", "789012", "01.02.2021", "01.02.2031");

    // Добавление виз в загран.паспорт Никиты
    foreignPassport.addVisa(Visa("Германия", "Шенген", "01.03.2022", "01.03.2025"));
    foreignPassport.addVisa(Visa("Франция", "Шенген", "01.04.2023", "01.04.2026"));

    // Вывод информации о паспортах
    cout << "Паспорт Алексея:" << endl;
    alexPassport.print();

    cout << "\nПаспорт Никиты:" << endl;
    nikitaPassport.print();

    cout << "\nЗаграничный паспорт Никиты:" << endl;
    foreignPassport.print();

    return 0;
}