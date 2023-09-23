#include <iostream>
#include <map>

using namespace std;

int main() {
  string text;
  getline(cin, text);

  cout << "Text: " << text << endl;

  map<char, int> m;
  for (size_t i = 0; i < text.length(); i++)  {
    char c = text[i];
    
    if (isalpha(c)){
      char upper = toupper(c);
      m[upper]++;
    }
  }

  map<char, int>::iterator it;
  for (it = m.begin(); it != m.end(); it++)
    {
      std::cout << it->first    // string (key)
        << ':'
        << it->second   // string's value 
        << std::endl;
    }
} 
