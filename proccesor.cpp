#include <iostream>
using namespace std;

#define AREA(w, h) ((w) * (h))
#define PERIMETER(w, h) (2 * (w) + 2 * (h))

int main() {
  int width, height;

  cout << "Введите ширину прямоугольника:";
  cin >> width;
  cout << "Введите высоту прямоугольника:";
  cin >> height;
  cout << "Площадь прямоугольника:" << AREA(width, height) << "\n";
  cout << "Периметр прямоугольника:" << PERIMETER(width, height) << "\n";

return 0;
}