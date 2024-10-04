#include <iostream>
using namespace std;

void insertMiddle(int** arr, int& size, int value, int index);
void insertBeginning(int** arr, int& size, int value);
void deleteEnd(int** arr, int& size);
void deleteMiddle(int** arr, int& size, int index);
void deleteBeginning(int** arr, int& size);

int main() {
  int arraySize = 5;
  int** arr = new int*[arraySize];
  for (int i = 0; i < arraySize; i++) {
    arr[i] = new int[1];
  }
  for (int i = 0; i < arraySize; i++) {
    arr[i][0] = i + 1;
  }
  
  insertMiddle(arr, arraySize, 10, 2);
  insertBeginning(arr, arraySize, 20);
  deleteEnd(arr, arraySize);
  deleteMiddle(arr, arraySize, 2);
  deleteBeginning(arr, arraySize);
  
  for (int i = 0; i < arraySize; i++) {
    cout << arr[i][0] << " ";
  }
  cout << endl;
  for (int i = 0; i < arraySize; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  return 0;
}

void insertMiddle(int** arr, int& size, int value, int index) {
  if (index < 1 || index >= size) {
    return;
  }
  size++;
  int** newArr = new int*[size];
  for (int i = 0; i < size; i++) {
    newArr[i] = new int[1];
  }
  for (int i = 0; i < index; i++) {
    newArr[i][0] = arr[i][0];
  }
  newArr[index][0] = value;
  for (int i = index; i < size - 1; i++) {
    newArr[i + 1][0] = arr[i][0];
  }
  for (int i = 0; i < size - 1; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  arr = newArr;
}
void insertBeginning(int** arr, int& size, int value) {
  size++;
  int** newArr = new int*[size];
  for (int i = 0; i < size; i++) {
   newArr[i] = new int[1];
}
  newArr[0][0] = value;
  for (int i = 1; i < size; i++) {
    newArr[i][0] = arr[i - 1][0];
  }
  for (int i = 0; i < size - 1; i++) {
   delete[] arr[i];
  }
  delete[] arr;
  arr = newArr;
}

void deleteEnd(int** arr, int& size) {
  if (size == 0) {
    return;
  }
  size--;
  int** newArr = new int*[size];
  for (int i = 0; i < size; i++) {
    newArr[i] = new int[1];
  }
  for (int i = 0; i < size; i++) {
    newArr[i][0] = arr[i][0];
  }
  for (int i = 0; i < size + 1; i++) {
    delete[] arr[i];
 }
  delete[] arr;
  arr = newArr;
}


void deleteMiddle(int** arr, int& size, int index) {
  if (index < 1 || index >= size) {
   return;
  }
  size--;
  int** newArr = new int*[size];
  for (int i = 0; i < size; i++) {
    newArr[i] = new int[1];
  }
  for (int i = 0; i < index; i++) {
    newArr[i][0] = arr[i][0];
  }
  for (int i = index; i < size; i++) {
    newArr[i][0] = arr[i + 1][0];
  }
  for (int i = 0; i < size + 1; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  arr = newArr;
}

void deleteBeginning(int** arr, int& size) {
  if (size == 0) {
    return;
  }
  size--;
  int** newArr = new int*[size];
  for (int i = 0; i < size; i++) {
    newArr[i] = new int[1];
  for (int i = 0; i < size; i++) {
    newArr[i][0] = arr[i + 1][0];
  }
  for (int i = 0; i < size + 1; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  arr = newArr;
}