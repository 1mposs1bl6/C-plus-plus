#ifndef KNIGA_H
#define KNIGA_H

#include <iostream>
#include <string>

using namespace std;

class kniga {
private:
  char* name;
  string author;
  int numberOfPages;
  bool isOpen;
  int currentPage;

public:
  kniga();
  kniga(char* name, string author, int numberOfPages);
  kniga(const kniga& other);
  ~kniga();

  char* getName() const;
  string getAuthor() { return author; }
  int getNumberOfPages() { return numberOfPages; }
  bool isOpen() { return isOpen; }
  int getCurrentPage() { return currentPage; }

  void setName(const char* name);
  void setAuthor(string author) { this->author = author; }
  void setNumberOfPages(int numberOfPages) { this->numberOfPages = numberOfPages; }
  void setIsOpen(bool isOpen) { this->isOpen = isOpen; }
  void setCurrentPage(int currentPage) { this->currentPage = currentPage; }

  void open();
  void close();
  void turnPage();
  void describe();

  bool operator==(const kniga& other) const;
  bool operator!=(const kniga& other) const;
  bool operator>(const kniga& other) const;
  bool operator<(const kniga& other) const;
  friend ostream& operator<<(ostream& os, const kniga& kniga);
  friend istream& operator>>(istream& is, kniga& kniga);
};

#endif