#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool ascending (int32_t i, int32_t j) { return (i<j); }

int32_t BinarySearch(vector<int32_t> arr, int32_t val) {
  sort(arr.begin(), arr.end(), ascending);
  for(int32_t i: arr) {
    cout << i << " ";
  }
  cout << '\n';
  
  bool found = false;
  uint16_t mid = 0;
  uint16_t start = 0;
  uint16_t end = arr.size();
  while(!found) {
    uint16_t value = arr[mid];
    if(val == value) {
      return mid;
    } else if(val > value) {
      start = mid;
    } else if(val < value) {
      end = mid;
    }
    cout << mid << " ";
    if(uint16_t((start+end)/2) == mid) { found = true; }
    mid = uint16_t((start+end)/2);
  }
  return -1;
}


int main() {
  vector<int32_t> arr = {9, 2, 1, 3, 4, 5, 8, 10, 10};
  int32_t val;
  cin >> val;
  cout << BinarySearch(arr, val);
  return 0;
}
