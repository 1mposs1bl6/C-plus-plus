#include <iostream>
using namespace std;

int main() {
  int a =10;
  int b = 20;
  int *p1= &a;
  int *p2 = &b;
  int distance = p1 - p2;
  cout << "Расстояние между a и b:" << distance << "\n";
  int size = sizeof(int);
  cout << "Расстояние в байтах:"<< distance * size << "\n";
  int num;
  cin >> num;
  int *pNum = &num;
  int *pSquare = new int;
  *pSquare = num * num;
  cout << "Квадрат:" << *pSquare << "\n";
  int *pCube = new int;
  *pCube = num * num * num;
  cout << "Куб:" << *pCube << "\n";
  int *pFourth= new int;
  *pFourth = num * num * num * num;
  cout << "Четвертая степень:" << *pFourth << "\n";
  int num1, num2;
  cin >> num1 >> num2;
  int *p1Num = &num1;
  int *p2Num = &num2;
  int *pSum = new int;
  *pSum = *p1Num + *p2Num;
  cout << "Сумма:"<< *pSum << "\n";

  delete pSquare;
  delete pCube;
  delete pFourth;
  delete pSum;
  return 0;
}