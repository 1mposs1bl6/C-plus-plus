#include <iostream>
using namespace std;

struct Point {
  int x;
  int y;
};
struct Rectangle {
  Point topLeft;
  Point bottomRight;
};
bool isPointInsideRectangle(const Rectangle& rect, const Point& point) {
  return point.x >= rect.topLeft.x && point.x <= rect.bottomRight.x &&
   point.y >= rect.topLeft.y && point.y <= rect.bottomRight.y;
}

int main() {

  Rectangle rect;
rect.topLeft.x = 1;
  rect.topLeft.y=2;
  rect.bottomRight.x = 5;
  rect.bottomRight.y= 4;
  Point point;
  point.x = 3;
  point.y =3;

  if (isPointInsideRectangle(rect, point)) {
  cout << "Точка находится внутри прямоугольника." << endl;
  } else {
   cout << "Точка находится вне прямоугольника." << endl;
  }
return 0;
}