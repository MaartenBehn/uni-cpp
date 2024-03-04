#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <list>

class Point {
};

int main() {
  std::string s;
  Point p;

  std::string &r = s;
  const Point &cr = p;

  unsigned int a[20];

  char **pp;
  std::vector<char> vec;

  std::map<Point, double> m;

  std::list<std::unique_ptr<std::string>> l;
}
  
