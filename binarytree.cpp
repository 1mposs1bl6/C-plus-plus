#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

class Vector {
public:
    struct Node {
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            this->next = nullptr;
        }
    };

private:
    Node* head;
    int size;
    int capacity;

public:
    Vector() {
        head = nullptr;
        size = 0;
        capacity = 0;
    }

    Vector(const Vector& other) {
        head = nullptr;
        size = 0;
        capacity = 0;
        for (int i = 0; i < other.size; i++) {
            Insert(i, other.data[i]);
        }
    }

    ~Vector() {
        Clear();
    }

    void Insert(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Ошибка: индекс вне границ массива." << endl;
            return;
        }

        if (size == capacity) {
            Resize(capacity * 2 + 1);
        }

        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс вне границ массива." << endl;
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        size--;
    }

    void RemoveByValue(int value) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->value == value) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                Node* temp = current;
                current = current->next;
                delete temp;
                size--;
            } else {
                previous = current;
                current = current->next;
            }
        }
    }

    void PopFront() {
        if (size == 0) {
            cout << "Ошибка: массив пуст." << endl;
            return;
        }
        RemoveAt(0);
    }

    void PopBack() {
        if (size == 0) {
            cout << "Ошибка: массив пуст." << endl;
            return;
        }
        RemoveAt(size - 1);
    }

    void TrimToSize() {
        if (size < capacity) {
            Resize(size);
        }
    }

    int IndexOf(int value) const {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

    int LastIndexOf(int value) const {
        Node* current = head;
        int index = 0;
        int lastIndex = -1;
        while (current != nullptr) {
            if (current->value == value) {
                lastIndex = index;
            }
            current = current->next;
            index++;
        }
        return lastIndex;
    }

    void Reverse() {
        Node* previous = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    void SortAsc() {
        int* data = new int[size];
        Node* current = head;
        int i = 0;
        while (current != nullptr) {
            data[i] = current->value;
            current = current->next;
            i++;
        }
        sort(data, data + size);
        current = head;
        i = 0;
        while (current != nullptr) {
            current->value = data[i];
            current = current->next;
            i++;
        }
        delete[] data;
    }

    void SortDesc() {
        int* data = new int[size];
        Node* current = head;
        int i = 0;
        while (current != nullptr) {
            data[i] = current->value;
            current = current->next;
            i++;
        }
        sort(data, data + size, greater<int>());
        current = head;
        i = 0;
        while (current != nullptr) {
            current->value = data[i];
            current = current->next;
            i++;
        }
        delete[] data;
    }

    void Print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    void Resize(int newCapacity) {
        Node* newHead = new Node(0);
        Node* current = head;
        Node* newCurrent = newHead;
        for (int i = 0; i < size; i++) {
            newCurrent->value = current->value;
            if (i < size - 1) {
                newCurrent->next = new Node(0);
                newCurrent = newCurrent->next;
            }
            current = current->next;
        }
        head = newHead;
        capacity = newCapacity;
    }

    void Clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
        capacity = 0;
    }
};

class Stack {
private:
    list<int> data;

public:
    void Push(int value) {
        data.push_front(value);
    }

    void Pop() {
        if (!data.empty()) {
            data.pop_front();
        } else {
            cout << "Ошибка: стек пуст." << endl;
        }
    }

    int Top() const {
        if (!data.empty()) {
            return data.front();
        } else {
            cout << "Ошибка: стек пуст." << endl;
            return -1;
        }
    }

    bool IsEmpty() const {
        return data.empty();
    }

    bool Contains(int value) const {
        return find(data.begin(), data.end(), value) != data.end();
    }

    void Print() const {
        for (auto it = data.begin(); it != data.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    void PushLessValue(int value) {
        if (IsEmpty() || value < Top()) {
            Push(value);
        }
    }
};


class Tree {
public:
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node* parent;

        Node(int value) {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
            this->parent = nullptr;
        }
    };

private:
    Node* root;

public:
    Tree() {
        root = nullptr;
    }

    ~Tree() {
        Clear(root);
    }

    void AddNode(int value) {
        if (root == nullptr) {
            root = new Node(value);
        } else {
            Node* current = root;
            while (true) {
                if (value < current->value) {
                    if (current->left == nullptr) {
                        current->left = new Node(value);
                        current->left->parent = current;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = new Node(value);
                        current->right->parent = current;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
        // Балансировка дерева
        Balance();
    }

    void PrintTree(Node* node) const {
        if (node != nullptr) {
            PrintTree(node->left);
            cout << node->value << " ";
            PrintTree(node->right);
        }
    }

    void PrintTree() const {
        cout << "Дерево: ";
        PrintTree(root);
        cout << endl;
    }

private:
    void Clear(Node* node) {
        if (node != nullptr) {
            Clear(node->left);
            Clear(node->right);
            delete node;
        }
    }

    void Balance() {
        // Проверка на вырожденность дерева
        if (IsDegenerate(root)) {
            // Перегоняем элементы в массив
            int* data = new int[CountNodes(root)];
            int i = 0;
            InOrderTraversal(root, data, i);
            // Перемешиваем массив
            ShuffleArray(data, CountNodes(root));
            // Перегоняем элементы из массива в дерево
            Clear(root);
            root = nullptr;
            for (int j = 0; j < CountNodes(root); j++) {
                AddNode(data[j]);
            }
            delete[] data;
        }
    }

    bool IsDegenerate(Node* node) {
        if (node == nullptr) {
            return false;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return true;
        }
        if (node->left != nullptr && node->right != nullptr) {
            return false;
        }
        return IsDegenerate(node->left) || IsDegenerate(node->right);
    }

    int CountNodes(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + CountNodes(node->left) + CountNodes(node->right);
    }

    void InOrderTraversal(Node* node, int* data, int& i) {
        if (node != nullptr) {
            InOrderTraversal(node->left, data, i);
            data[i] = node->value;
            i++;
            InOrderTraversal(node->right, data, i);
        }
    }

    void ShuffleArray(int* data, int size) {
        srand(time(nullptr));
        for (int i = size - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(data[i], data[j]);
        }
    }
};

class Kupyura {
private:
    int nominal;
    char* currency;
    bool isWhole;
    bool isInCirculation;

public:
    Kupyura() : Kupyura(100, "гривна", true, true) {}

    Kupyura(int nominal, char* currency, bool isWhole = true, bool isInCirculation = true) {
        this->nominal = nominal;
        this->currency = new char[strlen(currency) + 1];
        strcpy(this->currency, currency);
        this->isWhole = isWhole;
        this->isInCirculation = isInCirculation;
    }

    Kupyura(const Kupyura& other) {
        this->nominal = other.nominal;
        this->currency = new char[strlen(other.currency) + 1];
        strcpy(this->currency, other.currency);
        this->isWhole = other.isWhole;
        this->isInCirculation = other.isInCirculation;
    }

    ~Kupyura() {
        delete[] currency;
    }

    void describe() {
        cout << "Купюра номиналом " << nominal << " " << currency << "." << endl;
    }

    bool operator==(const Kupyura& other) const {
        return (nominal == other.nominal && strcmp(currency, other.currency) == 0);
    }

    bool operator!=(const Kupyura& other) const {
        return !(*this == other);
    }

    bool operator>(const Kupyura& other) const {
        return (nominal > other.nominal);
    }

    bool operator<(const Kupyura& other) const {
        return (nominal < other.nominal);
    }

    friend ostream& operator<<(ostream& os, const Kupyura& kupyura) {
        os << "Номинал: " << kupyura.nominal << endl;
        os << "Валюта: " << kupyura.currency << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Kupyura& kupyura) {
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
    // Тестирование дерева
    Tree tree;
    for (int i = 1; i <= 5000; i++) {
        tree.AddNode(i);
    }
    tree.PrintTree();

    return 0;
}