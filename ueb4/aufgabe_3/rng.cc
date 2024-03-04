#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Data {
public:
  mt19937 mt;
  
  float operator() (){
    float max = mt.max();
    return mt() / max; 
  };
};

int main() {
  vector<float> v;
  generate_n(inserter(v, v.end()), 100, Data());

  for (int i = 0; i < 100; i++) {
    cout << v[i] << '\n'; 
  }
}
