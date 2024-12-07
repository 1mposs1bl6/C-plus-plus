#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Device {
public:
    string manufacturer;
    string model;
    string name;
    int capacity;
    int count;

    Device(const string& manufacturer, const string& model, const string& name, int capacity, int count) :
        manufacturer(manufacturer), model(model), name(name), capacity(capacity), count(count) {}

    void setManufacturer(const string& manufacturer) { this->manufacturer = manufacturer; }
    void setModel(const string& model) { this->model = model; }
    void setName(const string& name) { this->name = name; }
    void setCapacity(int capacity) { this->capacity = capacity; }
    void setCount(int count) { this->count = count; }

    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    string getName() const { return name; }
    int getCapacity() const { return capacity; }
    int getCount() const { return count; }

    virtual void print() const {
        cout << "Производитель: " << manufacturer << endl;
        cout << "Модель: " << model << endl;
        cout << "Наименование: " << name << endl;
        cout << "Емкость: " << capacity << " Гб" << endl;
        cout << "Количество: " << count << endl;
    }

    virtual void load() const {
        cout << "Данные загружены." << endl;
    }

    virtual void save() const {
        cout << "Данные сохранены." << endl;
    }
};

class PortableHDD : public Device {
public:
    PortableHDD(const string& manufacturer, const string& model, const string& name, int capacity, int count) :
        Device(manufacturer, model, name, capacity, count) {}

    void print() const override {
        cout << "Портативный жесткий диск:" << endl;
        Device::print();
    }

    void load() const override {
        cout << "Данные с портативного жесткого диска загружены." << endl;
    }

    void save() const override {
        cout << "Данные на портативный жесткий диск сохранены." << endl;
    }
};

class Smartphone : public Device {
public:
    Smartphone(const string& manufacturer, const string& model, const string& name, int capacity, int count) :
        Device(manufacturer, model, name, capacity, count) {}

    void print() const override {
        cout << "Смартфон:" << endl;
        Device::print();
    }

    void load() const override {
        cout << "Данные со смартфона загружены." << endl;
    }

    void save() const override {
        cout << "Данные на смартфон сохранены." << endl;
    }
};

class Tablet : public Device {
public:
    Tablet(const string& manufacturer, const string& model, const string& name, int capacity, int count) :
        Device(manufacturer, model, name, capacity, count) {}

    void print() const override {
        cout << "Планшет:" << endl;
        Device::print();
    }

    void load() const override {
        cout << "Данные с планшета загружены." << endl;
    }

    void save() const override {
        cout << "Данные на планшет сохранены." << endl;
    }
};

int main() {
    vector<Device*> devices;

    while (true) {
        cout << "\nЧто вы хотите сделать?\n";
        cout << "1. Добавить устройство\n";
        cout << "2. Удалить устройство\n";
        cout << "3. Показать информацию об устройстве\n";
        cout << "4. Изменить параметры устройства\n";
        cout << "5. Найти устройство по критерию\n";
        cout << "6. Выйти\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "\nКакой тип устройства вы хотите добавить?\n";
            cout << "1. Портативный жесткий диск\n";
            cout << "2. Смартфон\n";
            cout << "3. Планшет\n";

            int deviceType;
            cin >> deviceType;

            cout << "\nВведите информацию об устройстве:\n";
            string manufacturer, model, name;
            int capacity, count;
            cin >> manufacturer >> model >> name >> capacity >> count;

            if (deviceType == 1) {
                devices.push_back(new PortableHDD(manufacturer, model, name, capacity, count));
            } else if (deviceType == 2) {
                devices.push_back(new Smartphone(manufacturer, model, name, capacity, count));
            } else if (deviceType == 3) {
                devices.push_back(new Tablet(manufacturer, model, name, capacity, count));
            }
        } else if (choice == 2) {
            if (devices.empty()) {
                cout << "Список устройств пуст.\n";
            } else {
                cout << "\nВведите номер устройства для удаления:\n";
                int index;
                cin >> index;
                if (index >= 0 && index < devices.size()) {
                    delete devices[index];
                    devices.erase(devices.begin() + index);
                    cout << "Устройство удалено.\n";
                } else {
                    cout << "Неверный номер устройства.\n";
                }
            }
        } else if (choice == 3) {
            if (devices.empty()) {
                cout << "Список устройств пуст.\n";
            } else {
                cout << "\nВведите номер устройства для вывода информации:\n";
                int index;
                cin >> index;
                if (index >= 0 && index < devices.size()) {
                    devices[index]->print();
                    cout << "Тип устройства: " << typeid(*devices[index]).name() << endl;
                } else {
                    cout << "Неверный номер устройства.\n";
                }
            }
        } else if (choice == 4) {
            if (devices.empty()) {
                cout << "Список устройств пуст.\n";
            } else {
                cout << "\nВведите номер устройства для изменения параметров:\n";
                int index;
                cin >> index;
                if (index >= 0 && index < devices.size()) {
                    cout << "\nВведите новые параметры:\n";
                    string manufacturer, model, name;
                    int capacity, count;
                    cin >> manufacturer >> model >> name >> capacity >> count;

                    devices[index]->setManufacturer(manufacturer);
                    devices[index]->setModel(model);
                    devices[index]->setName(name);
                    devices[index]->setCapacity(capacity);
                    devices[index]->setCount(count);

                    cout << "Параметры изменены.\n";
                } else {
                    cout << "Неверный номер устройства.\n";
                }
            }
        } else if (choice == 5) {
            if (devices.empty()) {
                cout << "Список устройств пуст.\n";
            } else {
                cout << "\nВведите критерий поиска (производитель, модель, наименование):\n";
                string criterion;
                cin >> criterion;

                bool found = false;
                for (int i = 0; i < devices.size(); i++) {
                    if (devices[i]->getManufacturer() == criterion ||
                        devices[i]->getModel() == criterion ||
                        devices[i]->getName() == criterion) {
                        devices[i]->print();
                        cout << "Тип устройства: " << typeid(*devices[i]).name() << endl;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "Устройства, соответствующие критерию, не найдены.\n";
                }
            }
        } else if (choice == 6) {
            break;
        } else {
            cout << "Неверный выбор.\n";
        }
    }

    for (Device* device : devices) {
        delete device;
    }

    return 0;
}