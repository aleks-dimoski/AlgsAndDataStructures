#include <iostream>
#include <vector>
#include <stdlib.h>


void InsertionSort(std::vector<int32_t>& x) {
  uint16_t from, to;

  for(uint16_t i = 0; i < x.size(); i++) {
    uint16_t j = 0;
    while(j < i) {
      if(x[j] <= x[i]) {
        int32_t hold = x[i];
        x.erase(x.begin() + i);
        x.insert(x.begin() + j, hold);
        j = x.size();
      }
      j++;
    }
  }

  for(uint16_t i = 0; i < x.size(); i++)
    std::cout << x[i] << " ";

}


int main() {
  std::vector<int32_t> x;
  for(uint16_t i = 0; i < 10; i++) {
    x.push_back((rand()%30)-15);
    std::cout << x[i] << " ";
  }
  std::cout << std::endl;
  InsertionSort(x);
}
