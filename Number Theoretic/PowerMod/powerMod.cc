#include <iostream>

using namespace std;

uint32_t powermod(uint32_t x, uint32_t n, uint32_t m) {
  uint32_t prod = 1;
  while(n>0) {
    if(n % 2 != 0)
      prod = (prod*x) % m;
    x = (x*x)%m;
    n = n/2;
  }
  return x;
}

int main() {
  cout << powermod(50, 11, 3);
  return 0;
}
