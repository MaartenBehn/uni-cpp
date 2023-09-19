#include <iostream>
#include <map>
#include <vector>
#include <algorithm> 

using namespace std;

bool cmp(pair<char, int>& a,
        pair<char, int>& b)
{
    return a.second > b.second;
}

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

  vector<pair<char, int>> A;
  for (auto& it : m){
    A.push_back(it);
  }
 
  std::sort(A.begin(), A.end(), cmp);

  for (size_t i = 0; i < A.size(); i++)
  {
    std::cout << A[i].first    // string (key)
	      << ':'
	      << A[i].second   // string's value 
	      << std::endl;
  }
} 
