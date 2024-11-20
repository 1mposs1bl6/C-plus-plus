#include <iostream>
#include <stdexcept>
using namespace std;

class Vector {
private:
    int* data; 
    int size; 
    int capacity; 

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i]; // копируем старые данные
        }
        delete[] data;
        data = newData; // новый массив на месте старого
        capacity = newCapacity;
    }

public:
    Vector(int initialCapacity = 4) : size(0), capacity(initialCapacity) {
        data = new int[capacity];
    }

    ~Vector() {
        delete[] data; // не забываем чистить память
    }

    void Insert(int index, int value) {
        if (index < 0 || index > size) {
            throw out_of_range("Индекс за пределами!");
        }
        if (size == capacity) {
            resize(capacity * 2); // увеличиваем массив, если надо
        }
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value; // вставляем элемент
        size++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Индекс за пределами!");
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1]; // сдвигаем элементы
        }
        size--;
    }

    void RemoveByValue(int value, bool removeAll = false) {
        for (int i = 0; i < size; ) {
            if (data[i] == value) {
                RemoveAt(i);
                if (!removeAll) break; // удаляем только первый, если не указано
            } else {
                i++;
            }
        }
    }

    void PopFront() {
        if (size == 0) throw underflow_error("Массив пустой!");
        RemoveAt(0); // удаляем первый элемент
    }

    void PopBack() {
        if (size == 0) throw underflow_error("Массив пустой!");
        size--; // просто уменьшаем размер
    }

    void TrimToSize() {
        resize(size); // убираем лишний запас
    }

    int IndexOf(int value) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) return i; // нашли элемент
        }
        return -1; // не нашли
    }

    int Get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Индекс за пределами!");
        }
        return data[index]; // возвращаем элемент
    }

    int GetSize() const {
        return size; // просто размер
    }

    void Print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " "; // выводим элементы через пробел
        }
        cout << endl;
    }
};

int main() {
    Vector v;

    v.Insert(0, 10);
    v.Insert(1, 20);
    v.Insert(2, 30);
    v.Insert(3, 40);

    cout << "Массив после вставок: ";
    v.Print();

    v.RemoveByValue(20);
    cout << "Массив после удаления 20: ";
    v.Print();

    v.PopFront();
    cout << "Массив после PopFront: ";
    v.Print();

    v.PopBack();
    cout << "Массив после PopBack: ";
    v.Print();

    v.TrimToSize();
    cout << "Массив после TrimToSize: ";
    v.Print();

    cout << "Индекс 30: " << v.IndexOf(30) << endl;

    return 0;
}
