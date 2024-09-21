#include <iostream>
using namespace std;


bool isLeapYear(int year) {
  if (year % 4 != 0) {
    return false;
  } else if (year % 100 == 0 && year % 400 != 0) {
    return false;
  } else {
    return true;
}

}
int daysDifference(int year1, int month1, int day1, int year2, int month2, int day2) {
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int totalDays1 = 0;
  int totalDays2 = 0;
  for (int i = 0; i < month1 - 1; i++) {
    totalDays1 += daysInMonth[i];
  }
  totalDays1 += day1;
  for (int i = 0; i < month2 - 1; i++) {
    totalDays2 += daysInMonth[i];
  }
  totalDays2 += day2;
  return totalDays2 - totalDays1; 
}

double average(int arr[], int size) {
  int sum = 0;
for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return (double)sum / size;
}

void countElements(int arr[], int size, int& positiveCount, int& negativeCount, int& zeroCount) {
  positiveCount = 0;
  negativeCount = 0;
  zeroCount = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > 0) {
      positiveCount++;
    } else if (arr[i] < 0) {
      negativeCount++;
    } else {
      zeroCount++;
    }
  }
}
int main() {
  return 0;
}