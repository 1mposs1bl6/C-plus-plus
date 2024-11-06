#ifndef KNIGA_H
#define KNIGA_H

#include <iostream>
#include <string>

using namespace std;

class kniga {
private:
  string name;
  string author;
  int numberOfPages;
  bool isOpen;
  int currentPage;

public:
  string getName() { return name; }
  string getAuthor() { return author; }
  int getNumberOfPages() { return numberOfPages; }
  bool isOpen() { return isOpen; }
  int getCurrentPage() { return currentPage; }

  void setName(string name) { this->name = name; }
  void setAuthor(string author) { this->author = author; }
  void setNumberOfPages(int numberOfPages) { this->numberOfPages = numberOfPages; }
  void setIsOpen(bool isOpen) { this->isOpen = isOpen; }
  void setCurrentPage(int currentPage) { this->currentPage = currentPage; }

  void open();
  void close();
  void turnPage();
  void describe();
};

#endif