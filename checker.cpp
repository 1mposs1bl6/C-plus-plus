#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
  string inputString;
  cout << "Введите строку: ";
  getline(cin, inputString);

  int wordCount = 0;
  int vowelCount = 0;
  int consonantCount = 0;
  int punctuationCount = 0;
  int digitCount = 0;
  int otherCount = 0;

  for (char c : inputString) {
    if (isspace(c)) {
      wordCount++;
    } else if (isalpha(c)) {
      if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u' || tolower(c) == 'y') {
        vowelCount++;
      } else {
        consonantCount++;
      }
    } else if (ispunct(c)) {
      punctuationCount++;
    } else if (isdigit(c)) {
      digitCount++;
    } else {
      otherCount++;
    }
  }

  // Учитываем последнее слово в строке
  wordCount++; 

  cout << "Всего символов – " << inputString.length() << ", из них:" << endl;
  cout << "Слов – " << wordCount << endl;
  cout << "Гласных - " << vowelCount << endl;
  cout << "Согласных - " << consonantCount << endl;
  cout << "Знаков пунктуации - " << punctuationCount << endl;
  cout << "Цифр – " << digitCount << endl;
  cout << "Др. символов – " << otherCount << endl;

  return 0;
}