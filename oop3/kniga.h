#ifndef KNIGA_H
#define KNIGA_H

#include <iostream>
#include <string>

using namespace std;

class Kniga {
private:
    string name;
    string author;
    int numberOfPages;
    bool isOpen;
    int currentPage;

public:
    // геттеры
    string getName() { return name; }
    string getAuthor() { return author; }
    int getNumberOfPages() { return numberOfPages; }
    bool isOpen() { return isOpen; }
    int getCurrentPage() { return currentPage; }

    // сеттеры
    void setName(string newName) { name = newName; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setNumberOfPages(int newNumberOfPages) { numberOfPages = newNumberOfPages; }
    void setIsOpen(bool newIsOpen) { isOpen = newIsOpen; }
    void setCurrentPage(int newCurrentPage) { currentPage = newCurrentPage; }

    void open();
    void close();
    void turnPage();
    void describe();
};

#endif