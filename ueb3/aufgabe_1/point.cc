#include <iostream>
#include <memory>
#include <vector>

class Point {
public:
  double x, y;
  Point() { x=0; y=0; }
  Point(double X, double Y) { x=X; y=Y; }
  void print(std::ostream &os) const { os << "[" << x << " " << y << "]"; }
  ~Point() { std::cout << "Destroyed: "; print(std::cout); std::cout << std::endl; }
};
std::ostream &operator<<(std::ostream &os, const Point &p) { p.print(os); return os; }
Point operator+(const Point &p1, const Point &p2) { return Point(p1.x + p2.x, p1.y + p2.y); }
Point operator-(const Point &p1, const Point &p2) { return Point(p1.x - p2.x, p1.y - p2.y); }
Point operator-(const Point &p1, int i) { return Point(p1.x - i, p1.y - i); }
Point operator*(const Point &p1, int i) { return Point(p1.x * i, p1.y * i); }
Point operator*(const Point &p1, const Point &p2) { return Point(p1.x * p2.x, p1.y * p2.y); }
void operator>>(std::istream &is, std::unique_ptr<Point> &p) {
  double x, y;
  std::cout << "X: " << std::endl;
  is >> x;
  std::cout << "Y: " << std::endl;
  is >> y;
  p->x = x;
  p->y = y;
}

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

  std::vector<std::unique_ptr<Point>> points;
  for (int i = 0; i < 4; i++){
    std::cout << "Next P:" << std::endl;
    
    std::unique_ptr<Point> p = std::make_unique<Point>();
    std::cin >> p;
    std::cout << "P" << i << ": " << *p << std::endl;

    points.push_back(move(p));
  }

  
  
}
