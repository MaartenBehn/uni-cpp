#include <iostream>

using namespace std;

void sayHello(string message){
  if (message.empty()) {
    cout << "Hello stranger!" <<endl;
  } else {
    cout << "I got a message: '" << message << "'" << endl;
  }
}

int main() {
  string name;
  getline(cin, name);

  sayHello(name);
}
