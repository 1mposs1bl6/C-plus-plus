  #include <iostream>
  #include <fstream>
  #include <string>
  using namespace std;

  int main() {
    string tema, slovo;

    cout << "Введите тему: ";
    getline(cin, tema);

    cout << "Введите слово: ";
    getline(cin, slovo);
    
    string filename = tema + ".txt";

    ofstream outfile;
    outfile.open(filename, ios::app)
    if (!outfile.is_open()) {
      outfile.open(filename, ios::out);
      outfile << slovo << endl;
      cout << "Создан файл " << filename << " и слово добавлено." << endl;
    } else {
      // если файл существует добавляем слово в конец файла
      outfile << slovo << endl;
      cout << "Слово добавлено в файл " << filename << endl;
    }

    outfile.close();
    return 0;
  }