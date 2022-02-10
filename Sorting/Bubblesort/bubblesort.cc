#include <iostream>
#include <vector>
using namespace std;

void swap(int32_t* a, int32_t* b) {
  int32_t* hold = a;
  a = b;
  b = hold;
}

vector<int32_t> bubblesort(vector<int32_t> x) {
  bool sorted = false;
  for(int32_t j = 0; j < x.size(); j++) {
    for(int32_t i = 0; i < x.size()-j-1; i++) {
      if(x[i] > x[i+1]) {
        swap(x[i], x[i+1]);
        sorted = false;
      }
    }
    if(sorted)
      return x;
    sorted = true;
    for(int16_t i = 0; i < x.size(); i++)
      cout << x[i] << " ";
    cout << '\n';
  }
  return x;
}

int main() {
  int32_t numNums;
  cout << "How many numbers? ";
  cin >> numNums;
  if(numNums <= 0) { return 0; }
  
  vector<int32_t> a(numNums);
  for(int16_t i = 0; i < numNums; i++)
    cin >> a[i];
  
  a = bubblesort(a);
  cout << '\n';
  for(uint16_t i = 0; i < a.size(); i++)
    cout << a[i] << " ";
  return 0;
}
