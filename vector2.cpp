#include <iostream>
#include <stdexcept>
#include <list>
#include <algorithm>
#include <random>
#include <fstream>
#include <string>

using namespace std;

class Vector {
private:
    int* data;
    int size;
    int capacity;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Vector(int initialCapacity = 4) : size(0), capacity(initialCapacity) {
        data = new int[capacity];
    }

    ~Vector() {
        delete[] data;
    }

    void Insert(int index, int value) {
        if (index < 0 || index > size) {
            throw out_of_range("Индекс за пределами!");
        }
        if (size == capacity) {
            resize(capacity * 2);
        }
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Индекс за пределами!");
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void RemoveByValue(int value, bool removeAll = false) {
        for (int i = 0; i < size; ) {
            if (data[i] == value) {
                RemoveAt(i);
                if (!removeAll) break;
            } else {
                i++;
            }
        }
    }

    void PopFront() {
        if (size == 0) throw underflow_error("Массив пустой!");
        RemoveAt(0);
    }

    void PopBack() {
        if (size == 0) throw underflow_error("Массив пустой!");
        size--;
    }

    void TrimToSize() {
        resize(size);
    }

    int IndexOf(int value) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) return i;
        }
        return -1;
    }

    int LastIndexOf(int value) const {
        for (int i = size - 1; i >= 0; i--) {
            if (data[i] == value) return i;
        }
        return -1;
    }

    void Reverse() {
        for (int i = 0; i < size / 2; i++) {
            swap(data[i], data[size - i - 1]);
        }
    }

    void SortAsc() {
        sort(data, data + size);
    }

    void SortDesc() {
        sort(data, data + size, greater<int>());
    }

    int Get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Индекс за пределами!");
        }
        return data[index];
    }

    int GetSize() const {
        return size;
    }

    void Print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

template <typename T>
class MyStack {
private:
    list<T> stack;

public:
    void Push(const T& value) {
        stack.push_back(value);
    }

    void Pop() {
        if (stack.empty()) {
            throw underflow_error("Стек пустой!");
        }
        stack.pop_back();
    }

    T Top() const {
        if (stack.empty()) {
            throw underflow_error("Стек пустой!");
        }
        return stack.back();
    }

    bool IsEmpty() const {
        return stack.empty();
    }

    bool Contains(const T& value) const {
        for (const auto& element : stack) {
            if (element == value) {
                return true;
            }
        }
        return false;
    }

    void Print() const {
        for (const auto& element : stack) {
            cout << element << " ";
        }
        cout << endl;
    }

    void PushLessValue(const T& value) {
        if (stack.empty() || value < stack.back()) {
            stack.push_back(value);
        }
    }
};

class WordGenerator {
private:
    ifstream wordFile;
    vector<string> words;

public:
    WordGenerator(const string& filename) : wordFile(filename) {
        string word;
        while (getline(wordFile, word)) {
            words.push_back(word);
        }
    }

    string generateWord() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(0, words.size() - 1);

        int index1 = distrib(gen);
        int index2 = distrib(gen);

        return words[index1] + words[index2].substr(1);
    }
};

int main() {
    //тесты для вектора
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
    cout << "Последний индекс 30: " << v.LastIndexOf(30) << endl;

    v.Reverse();
    cout << "Массив после Reverse: ";
    v.Print();

    v.SortAsc();
    cout << "Массив после SortAsc: ";
    v.Print();

    v.SortDesc();
    cout << "Массив после SortDesc: ";
    v.Print();

    //тесты для mystack
    MyStack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    cout << "Стек после добавления элементов: ";
    stack.Print();

    cout << "Содержит ли стек 2: " << stack.Contains(2) << endl;
    cout << "Содержит ли стек 4: " << stack.Contains(4) << endl;

    stack.Pop();
    cout << "Стек после удаления элемента: ";
    stack.Print();

    stack.PushLessValue(0);
    cout << "Стек после добавления меньшего элемента: ";
    stack.Print();

    //тесты для генератора
    WordGenerator wordGen("words.txt");
    for (int i = 0; i < 5; i++) {
        cout << "Сгенерированное слово: " << wordGen.generateWord() << endl;
    }

    return 0;
}