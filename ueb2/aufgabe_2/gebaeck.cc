#include <iostream>

class Gebaeck {
public:
  virtual void show(std::ostream &) const = 0;
};

class Toast : public Gebaeck {
public:
  void show(std::ostream &stream) const {
    stream << "Toast";
  }
};

std::ostream &operator<<(std::ostream &os, const Gebaeck &g) {
  g.show(os);
  return os;
}

int main() {
  Toast toast = Toast();
  std::cout << toast << std::endl;
}


