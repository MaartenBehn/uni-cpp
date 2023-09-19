#include <iostream>

class Point {
public:
  double x, y;
  Point(double X, double Y) { x=X; y=Y; }
  void print(std::ostream &os) const { os << "[X: " << x << " Y: " << y << "]"; }
};
std::ostream &operator<<(std::ostream &os, const Point &p) { p.print(os); return os; }
Point operator+(const Point &p1, const Point &p2) { return Point(p1.x + p2.x, p1.y + p2.y); }
Point operator-(const Point &p1, const Point &p2) { return Point(p1.x - p2.x, p1.y - p2.y); }
Point operator-(const Point &p1, int i) { return Point(p1.x - i, p1.y - i); }
Point operator*(const Point &p1, int i) { return Point(p1.x * i, p1.y * i); }
Point operator*(const Point &p1, const Point &p2) { return Point(p1.x * p2.x, p1.y * p2.y); }

int main() {
  const Point p1 = Point(5, 8);
  const Point p2 = Point(7, 3);
  std::cout << "P1: " << p1  << std::endl;
  std::cout << "P2: " << p2 << std::endl;
  std::cout << "P1 + P2: " << p1 + p2 << std::endl;
  std::cout << "P1 - P2: " << p1 - p2 << std::endl;
  std::cout << "P1 - 2:  " << p1 - 2.0 << std::endl;
  std::cout << "P1 * 2:  " << p1 * 2.0 << std::endl;
  std::cout << "P1 * P2: " << p1 * p2 << std::endl;
}
