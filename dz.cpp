#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
  srand(time(0));
  int a[5];
  cout << "введите 5 чисел ";
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }
  cout << "массив в обратном порядке ";
  for (int i = 4; i > 0; i--) { 
    cout << a[i] << " ";
  }
  cout << "\n";
  int b[20];
  for (int i = 0; i < 20; i++) {
    b[i] = rand() % 100;
  }
  cout << "четные элементы ";
  for (int i = 0; i < 20; i += 2) {
    cout << b[i] << " ";
  }
  cout << "\n";
  int c[10];
  int count = 0;
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    c[i] = rand() % 41 - 20;
    if (c[i] > 0) {
      count++;
      sum += c[i];
    }
  }
  cout << "количество" << count << "\n";
  cout << "сумма" << sum << "\n";
  cout << "среднее" << (double)sum / count << "\n";
  char d[100];
  int digits = 0, letters = 0, punctuation = 0;
  for (int i = 0; i <= 100; i++) { 
    d[i] = rand() % 94 + 33;
    if (isdigit(d[i])) {
      digits++;
    } else if (isalpha(d[i])) {
      letters++;
    } else {
      punctuation++;
    }
  }
  cout << "цифр" << digits << "\n";
  cout << "букв" << letters << "\n";
  cout << "знаков пунктуации" << punctuation << "\n";
  int e[100];
  int num, counter = 0;
  cout << "введите число ";
  cin >> num;
  for (int i = 0; i < 100; i++) {
    e[i] = rand() % 100;
    if (e[i] == num) {
      counter++;
    }
  }
  cout << "встречается" << counter << " раз\n";
  int f[20];
  int sum2 = 0;
  bool foundNegative = false;
  for (int i = 0; i < 20; i++) {
    f[i] = rand() % 41 - 10;
    if (f[i] < 0 && !foundNegative) {
      foundNegative = true;
    } else if (foundNegative) {
      sum2 += f[i];
    }
  }
  cout << "сумма" << sum2 << "\n";
  return 0;
}
