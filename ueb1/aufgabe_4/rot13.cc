#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

char f(char x, unsigned int ofs) {
  return (x + ofs) % 26;
}

char rot(char c, unsigned int ofs) {
  if (isupper(c))
    return f(c - 'A', ofs) + 'A';
  else if (islower(c))
    return f(c - 'a', ofs) + 'a';
  else
    return c;
}

int main() {
  string buf;

  while (getline(cin, buf)) {
    transform(buf.begin(), buf.end(), buf.begin(), bind(rot, placeholders::_1, 3));
    cout << buf << endl;
  }
}

// a)
// Es verschiebt alle charaktere in der input Datei um 13 stellen. Im Zahlen Raum von [0..26].
// c)
// es ist alles wieder gleich.

