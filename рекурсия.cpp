#include <iostream>
using namespace std;

void printNumbers(int n, int current = 1) {
  if (current <= n) {
    cout << current << " ";
   printNumbers(n, current + 1);
  }
}
void printRange(int a, int b, int current = a) {
  if (a < b) {
    if (current <= b) {
      cout << current << " ";
      printRange(a, b, current + 1);
    }
  } else {
    if (current >= b) {
      cout << current << "";
      printRange(a, b, current - 1);
    }
}
}

bool isPowerOfTwo(int n) {
  if (n == 1) {
    return true;
  } else if (n % 2 != 0 || n == 0) {
    return false;
  } else {
    return isPowerOfTwo(n - 1); 
 }
}


int main() {
  int n;
  cin >> n;
  printNumbers(n);
  cout << "\n";
  return 0;
}