#include <iostream>
#include <string>

using namespace std;

class chaynik {
private:
    string material;
    int volume;
    bool isOn;
    char* brand;

public:
    chaynik() : chaynik("пластик", 1) {}

    chaynik(string material, int volume) {
        this->material = material;
        this->volume = volume;
        this->isOn = false;
        this->brand = new char[10];
        strcpy(this->brand, "No brand");
    }

    chaynik(const chaynik& other) {
        this->material = other.material;
        this->volume = other.volume;
        this->isOn = other.isOn;
        this->brand = new char[strlen(other.brand) + 1];
        strcpy(this->brand, other.brand);
    }

    ~chaynik() {
        delete[] brand;
    }

    void boil() {
        if (isOn) {
            cout << "Чайник уже кипит!" << endl;
        } else {
            cout << "Чайник закипает..." << endl;
            isOn = true;
        }
    }

    void pour() {
        if (isOn) {
            cout << "Чайник кипит, будь осторожен!" << endl;
        } else {
            cout << "Чайник пуст." << endl;
        }
    }

    void describe() {
        cout << "Чайник из " << material << ", объемом " << volume << " литра." << endl;
        cout << "Бренд: " << brand << endl;
    }

    bool operator==(const chaynik& other) const {
        return (material == other.material && volume == other.volume && strcmp(brand, other.brand) == 0);
    }

    bool operator!=(const chaynik& other) const {
        return !(*this == other);
    }

    bool operator>(const chaynik& other) const {
        return (volume > other.volume);
    }

    bool operator<(const chaynik& other) const {
        return (volume < other.volume);
    }

    friend ostream& operator<<(ostream& os, const chaynik& chaynik) {
        os << "Материал: " << chaynik.material << endl;
        os << "Объем: " << chaynik.volume << " литра" << endl;
        os << "Бренд: " << chaynik.brand << endl;
        return os;
    }

    friend istream& operator>>(istream& is, chaynik& chaynik) {
        string material;
        int volume;
        char brand[10];

        cout << "Введите материал чайника: ";
        getline(is, material);
        cout << "Введите объем чайника (в литрах): ";
        is >> volume;
        cout << "Введите бренд чайника: ";
        is >> brand;

        chaynik.material = material;
        chaynik.volume = volume;
        chaynik.brand = new char[strlen(brand) + 1];
        strcpy(chaynik.brand, brand);

        return is;
    }

    char* getBrand() const {
        return brand;
    }

    void setBrand(const char* brand) {
        delete[] this->brand;
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
    }

    void setMaterial(string material) {
        this->material = material;
    }

    void setVolume(int volume) {
        this->volume = volume;
    }

    void setIsOn(bool isOn) {
        this->isOn = isOn;
    }

    void turnOn() {
        if (isOn) {
            cout << "Чайник уже включен." << endl;
        } else {
            cout << "Чайник включен!" << endl;
            isOn = true;
        }
    }

    void turnOff() {
        if (isOn) {
            cout << "Чайник выключен." << endl;
            isOn = false;
        } else {
            cout << "Чайник уже выключен." << endl;
        }
    }

    void heatUp() {
        if (isOn) {
            boil();
        } else {
            cout << "Чайник не включен." << endl;
        }
    }

    explicit operator std::string() const {
        return "Чайник: материал=" + material + ", объем=" + to_string(volume) + ", бренд=" + brand;
    }
};

class kniga {
private:
    char* name;
    string author;
    int numberOfPages;
    bool isOpen;
    int currentPage;

public:
    kniga() : kniga("Название книги", "Автор", 100) {}

    kniga(char* name, string author, int numberOfPages) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->author = author;
        this->numberOfPages = numberOfPages;
        isOpen = false;
        currentPage = 0;
    }

    kniga(const kniga& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->author = other.author;
        this->numberOfPages = other.numberOfPages;
        this->isOpen = other.isOpen;
        this->currentPage = other.currentPage;
    }

    ~kniga() {
        delete[] name;
    }

    void open() {
        isOpen = true;
        cout << "Книга открыта!" << endl;
    }

    void close() {
        isOpen = false;
        cout << "Книга закрыта." << endl;
    }

    void turnPage() {
        if (isOpen) {
            currentPage++;
            cout << "Страница перевернута!" << endl;
        } else {
            cout << "Книга закрыта." << endl;
        }
    }

    void describe() {
        cout << "Книга " << name << " автора " << author << ", всего страниц: " << numberOfPages << "." << endl;
    }

    bool operator==(const kniga& other) const {
        return (strcmp(name, other.name) == 0 && author == other.author && numberOfPages == other.numberOfPages);
    }

    bool operator!=(const kniga& other) const {
        return !(*this == other);
    }

    bool operator>(const kniga& other) const {
        return (numberOfPages > other.numberOfPages);
    }

    bool operator<(const kniga& other) const {
        return (numberOfPages < other.numberOfPages);
    }

    friend ostream& operator<<(ostream& os, const kniga& kniga) {
        os << "Название: " << kniga.name << endl;
        os << "Автор: " << kniga.author << endl;
        os << "Количество страниц: " << kniga.numberOfPages << endl;
        return os;
    }

    friend istream& operator>>(istream& is, kniga& kniga) {
        char name[100];
        string author;
        int numberOfPages;

        cout << "Введите название книги: ";
        is.getline(name, 100);
        cout << "Введите автора: ";
        getline(is, author);
        cout << "Введите количество страниц: ";
        is >> numberOfPages;

        kniga.name = new char[strlen(name) + 1];
        strcpy(kniga.name, name);
        kniga.author = author;
        kniga.numberOfPages = numberOfPages;

        return is;
    }

    char* getName() const {
        return name;
    }

    void setName(const char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setAuthor(string author) {
        this->author = author;
    }

    void setNumberOfPages(int numberOfPages) {
        this->numberOfPages = numberOfPages;
    }

    void setIsOpen(bool isOpen) {
        this->isOpen = isOpen;
    }

    void setCurrentPage(int currentPage) {
        this->currentPage = currentPage;
    }

    explicit operator std::string() const {
        return "Книга: название=" + name + ", автор=" + author + ", страниц=" + to_string(numberOfPages);
    }
};

class telefon {
private:
    char* model;
    string operatorName;
    int batteryLevel;
    bool isPhoneTurnedOn;
    bool isCurrentlyCalling;

public:
    telefon() : telefon("iPhone", "Киевстар", 100) {}

    telefon(char* model, string operatorName, int batteryLevel) {
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
        this->operatorName = operatorName;
        this->batteryLevel = batteryLevel;
        this->isPhoneTurnedOn = false;
        this->isCurrentlyCalling = false;
    }

    telefon(const telefon& other) {
        this->model = new char[strlen(other.model) + 1];
        strcpy(this->model, other.model);
        this->operatorName = other.operatorName;
        this->batteryLevel = other.batteryLevel;
        this->isPhoneTurnedOn = other.isPhoneTurnedOn;
        this->isCurrentlyCalling = other.isCurrentlyCalling;
    }

    ~telefon() {
        delete[] model;
    }

    void turnOn() {
        isPhoneTurnedOn = true;
        cout << "Телефон включен!" << endl;
    }

    void turnOff() {
        isPhoneTurnedOn = false;
        cout << "Телефон выключен." << endl;
    }

    void makeCall() {
        if (isPhoneTurnedOn) {
            isCurrentlyCalling = true;
            cout << "Звонок идет!" << endl;
        } else {
            cout << "Телефон выключен." << endl;
        }
    }

    void describe() {
        cout << "Модель: " << model << ", Оператор: " << operatorName << ", Батарея: " << batteryLevel << "%" << endl;
    }

    bool operator==(const telefon& other) const {
        return (strcmp(model, other.model) == 0 && operatorName == other.operatorName && batteryLevel == other.batteryLevel);
    }

    bool operator!=(const telefon& other) const {
        return !(*this == other);
    }

    bool operator>(const telefon& other) const {
        return (batteryLevel > other.batteryLevel);
    }

    bool operator<(const telefon& other) const {
        return (batteryLevel < other.batteryLevel);
    }

    friend ostream& operator<<(ostream& os, const telefon& telefon) {
        os << "Модель: " << telefon.model << endl;
        os << "Оператор: " << telefon.operatorName << endl;
        os << "Батарея: " << telefon.batteryLevel << "%" << endl;
        return os;
    }

    friend istream& operator>>(istream& is, telefon& telefon) {
        char model[100];
        string operatorName;
        int batteryLevel;

        cout << "Введите модель телефона: ";
        is.getline(model, 100);
        cout << "Введите оператора: ";
        getline(is, operatorName);
        cout << "Введите уровень заряда батареи (%): ";
        is >> batteryLevel;

        telefon.model = new char[strlen(model) + 1];
        strcpy(telefon.model, model);
        telefon.operatorName = operatorName;
        telefon.batteryLevel = batteryLevel;

        return is;
    }

    char* getModel() const {
        return model;
    }

    void setModel(const char* model) {
        delete[] this->model;
        this->model = new char[strlen(model) + 1];
        strcpy(this->model, model);
    }

    void setOperatorName(string operatorName) {
        this->operatorName = operatorName;
    }

    void setBatteryLevel(int batteryLevel) {
        this->batteryLevel = batteryLevel;
    }

    void setIsOn(bool isOn) {
        this->isPhoneTurnedOn = isOn;
    }

    void setIsCalling(bool isCalling) {
        this->isCurrentlyCalling = isCalling;
    }

    explicit operator std::string() const {
        return "Телефон: модель=" + model + ", оператор=" + operatorName + ", заряд=" + to_string(batteryLevel) + "%";
    }
};

class gelievaiaRuchka {
private:
    char* inkColor;
    string brand;
    bool isOpen;
    bool hasInk;
    int inkLevel;

public:
    gelievaiaRuchka() : gelievaiaRuchka("Черный", "Bic", true, 100) {}

    gelievaiaRuchka(char* inkColor, string brand, bool hasInk, int inkLevel) {
        this->inkColor = new char[strlen(inkColor) + 1];
        strcpy(this->inkColor, inkColor);
        this->brand = brand;
        this->hasInk = hasInk;
        this->inkLevel = inkLevel;
        isOpen = false;
    }

    gelievaiaRuchka(const gelievaiaRuchka& other) {
        this->inkColor = new char[strlen(other.inkColor) + 1];
        strcpy(this->inkColor, other.inkColor);
        this->brand = other.brand;
        this->hasInk = other.hasInk;
        this->inkLevel = other.inkLevel;
        this->isOpen = other.isOpen;
    }

    ~gelievaiaRuchka() {
        delete[] inkColor;
    }

    void open() {
        isOpen = true;
        cout << "Ручка открыта!" << endl;
    }

    void close() {
        isOpen = false;
        cout << "Ручка закрыта." << endl;
    }

    void write() {
        if (isOpen && hasInk) {
            inkLevel--;
            cout << "Пишу..." << endl;
        } else {
            cout << "Ручка не открыта или чернила закончились." << endl;
        }
    }

    void describe() {
        cout << "Ручка марки " << brand << ", цвет чернил: " << inkColor << ", уровень чернил: " << inkLevel << "%" << endl;
    }

    bool operator==(const gelievaiaRuchka& other) const {
        return (strcmp(inkColor, other.inkColor) == 0 && brand == other.brand && inkLevel == other.inkLevel);
    }

    bool operator!=(const gelievaiaRuchka& other) const {
        return !(*this == other);
    }

    bool operator>(const gelievaiaRuchka& other) const {
        return (inkLevel > other.inkLevel);
    }

    bool operator<(const gelievaiaRuchka& other) const {
        return (inkLevel < other.inkLevel);
    }

    friend ostream& operator<<(ostream& os, const gelievaiaRuchka& ruchka) {
        os << "Марка: " << ruchka.brand << endl;
        os << "Цвет чернил: " << ruchka.inkColor << endl;
        os << "Уровень чернил: " << ruchka.inkLevel << "%" << endl;
        return os;
    }

    friend istream& operator>>(istream& is, gelievaiaRuchka& ruchka) {
        char inkColor[100];
        string brand;
        int inkLevel;

        cout << "Введите цвет чернил: ";
        is.getline(inkColor, 100);
        cout << "Введите марку ручки: ";
        getline(is, brand);
        cout << "Введите уровень чернил: ";
        is >> inkLevel;

        ruchka.inkColor = new char[strlen(inkColor) + 1];
        strcpy(ruchka.inkColor, inkColor);
        ruchka.brand = brand;
        ruchka.inkLevel = inkLevel;

        return is;
    }

    char* getInkColor() const {
        return inkColor;
    }

    void setInkColor(const char* inkColor) {
        delete[] this->inkColor;
        this->inkColor = new char[strlen(inkColor) + 1];
        strcpy(this->inkColor, inkColor);
    }

    void setBrand(string brand) {
        this->brand = brand;
    }

    void setIsOpen(bool isOpen) {
        this->isOpen = isOpen;
    }

    void setHasInk(bool hasInk) {
        this->hasInk = hasInk;
    }

    void setInkLevel(int inkLevel) {
        this->inkLevel = inkLevel;
    }

    explicit operator std::string() const {
        return "Ручка: цвет=" + inkColor + ", бренд=" + brand + ", уровень чернил=" + to_string(inkLevel) + "%";
    }
};

class kupyura {
private:
    int nominal;
    char* currency;
    bool isWhole;
    bool isInCirculation;

public:
    kupyura() : kupyura(100, "гривна", true, true) {}

    kupyura(int nominal, char* currency, bool isWhole = true, bool isInCirculation = true) {
        this->nominal = nominal;
        this->currency = new char[strlen(currency) + 1];
        strcpy(this->currency, currency);
        this->isWhole = isWhole;
        this->isInCirculation = isInCirculation;
    }

    kupyura(const kupyura& other) {
        this->nominal = other.nominal;
        this->currency = new char[strlen(other.currency) + 1];
        strcpy(this->currency, other.currency);
        this->isWhole = other.isWhole;
        this->isInCirculation = other.isInCirculation;
    }

    ~kupyura() {
        delete[] currency;
    }

    void describe() {
        cout << "Купюра номиналом " << nominal << " " << currency << "." << endl;
    }

    bool operator==(const kupyura& other) const {
        return (nominal == other.nominal && strcmp(currency, other.currency) == 0);
    }

    bool operator!=(const kupyura& other) const {
        return !(*this == other);
    }

    bool operator>(const kupyura& other) const {
        return (nominal > other.nominal);
    }

    bool operator<(const kupyura& other) const {
        return (nominal < other.nominal);
    }

    friend ostream& operator<<(ostream& os, const kupyura& kupyura) {
        os << "Номинал: " << kupyura.nominal << endl;
        os << "Валюта: " << kupyura.currency << endl;
        return os;
    }

    friend istream& operator>>(istream& is, kupyura& kupyura) {
        int nominal;
        char currency[100];

        cout << "Введите номинал купюры: ";
        is >> nominal;
        cout << "Введите валюту: ";
        is.getline(currency, 100);

        kupyura.nominal = nominal;
        kupyura.currency = new char[strlen(currency) + 1];
        strcpy(kupyura.currency, currency);

        return is;
    }

    char* getCurrency() const {
        return currency;
    }

    void setCurrency(const char* currency) {
        delete[] this->currency;
        this->currency = new char[strlen(currency) + 1];
        strcpy(this->currency, currency);
    }

    void setNominal(int nominal) {
        this->nominal = nominal;
    }

    void setIsWhole(bool isWhole) {
        this->isWhole = isWhole;
    }

    void setIsInCirculation(bool isInCirculation) {
        this->isInCirculation = isInCirculation;
    }

    explicit operator std::string() const {
        return "Купюра: номинал=" + to_string(nominal) + ", валюта=" + currency;
    }
};

int main() {
    chaynik myChaynik("пластик", 1);
    kniga myKniga("Война и мир", "Лев Толстой", 1225);
    telefon myTelefon("iPhone 13 Pro", "Киевстар", 80);
    gelievaiaRuchka myRuchka("Синий", "Bic", true, 100);
    kupyura myKupyura(500, "гривны");

    cout << "Чайник: " << static_cast<string>(myChaynik) << endl;
    cout << "Книга: " << static_cast<string>(myKniga) << endl;
    cout << "Телефон: " << static_cast<string>(myTelefon) << endl;
    cout << "Ручка: " << static_cast<string>(myRuchka) << endl;
    cout << "Купюра: " << static_cast<string>(myKupyura) << endl;

    return 0;
}