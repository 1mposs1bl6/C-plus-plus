#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {

  char text[100];
  char symbol;

  cout << "Введите строку текста: ";
  cin.getline(text, 100);
  cout << "Введите символ: ";
  cin >> symbol;

  int count = 0;
  int index = 0;
  while (text[index] != '\0') {
    if (text[index] == symbol) {
      count++;
      cout << "Индекс совпадения: " << index << "\n";
    }
    index++;
  }
  cout << "Количество совпадений: " << count << "\n\n";
  char str[100];
  cout << "Введите текст на английском языке: ";
  cin.ignore();
  cin.getline(str, 100);

  int words = 0;
  int vowels = 0;
  int consonants = 0;
  int punctuation = 0;
 int digits = 0;
  int others = 0;

  int i = 0;
  while (str[i] != '\0') {
    if (isspace(str[i])) {
    words++;
    } else if (isalpha(str[i])) {
     if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
       vowels++;
      } else {
       consonants++;
      }
    } else if (ispunct(str[i])) {
     punctuation++;
    } else if (isdigit(str[i])) {
      digits++;
    } else {
     others++;
    }
    i++;
  }
  words++;
  cout << "Всего символов в строке текста – " << strlen(str) << ", из них: " << "\n";
  cout << "Слов – " << words << "\n";
  cout << "Гласных букв - " << vowels << "\n";
  cout << "Согласных букв - " << consonants << "\n";
  cout << "Знаков пунктуации - " << punctuation << "\n";
  cout << "Цифр – " << digits << "\n";
  cout << "Других символов – " << others << "\n\n";
  char sentence[100];
  cout << "Введите предложение: ";
  cin.getline(sentence, 100);

  int wordCount = 0;
 int totalLength = 0;
  int j = 0;
  while (sentence[j] != '\0') {
    if (isspace(sentence[j])) {
      wordCount++;
  } else {
      totalLength++;
    }
    j++;
  }
  wordCount++;
  if (wordCount > 0) {
    cout << "Средняя длина слова: " << (double)totalLength / wordCount << "\n\n";
  }
  char palindrome[100];
 cout << "Введите строку: ";
  cin.getline(palindrome, 100);
  int k = 0;
  while (palindrome[k] != '\0') {
   palindrome[k] = tolower(palindrome[k]);
    k++;
  }

 int left = 0;
  int right = strlen(palindrome) - 1;
  bool isPalindrome = true;
  while (left < right) {
    if (palindrome[left] != palindrome[right]) {
    isPalindrome = false;
      break;
    }
    left++;
    right--;
  }
if (isPalindrome) {
    cout << "Строка является палиндромом." << "\n\n";
  } else {
  cout << "Строка не является палиндромом." << "\n\n";
  }
  char text2[100];
  char wordToCount[20];
  cout << "Введите текст:";
  cin.getline(text2, 100);
  cout << "Введите слово для подсчета:";
  cin.getline(wordToCount, 20);
  int wordCount2 = 0;
  char* token = strtok(text2, " ");
  while (token != NULL) {
    if (strcmp(token, wordToCount) == 0) {
      wordCount2++;
    }
   token = strtok(NULL, " ");
  }
  cout << "Слово \"" << wordToCount << "\" встречается " << wordCount2 << " раз." << endl;
  return 0;
}