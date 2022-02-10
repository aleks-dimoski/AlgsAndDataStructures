#include <iostream>
#include <stdlib.h>

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

uint32_t Fermat(uint32_t p, uint32_t n, uint32_t k) {
  for(uint16_t i = 0; i < k; i++) {
    uint32_t a = rand()%(n-3) + 2;
    if(powermod(a, p-1, p))
      return false;
    return true;
  }
  return false;
}

int main() {
  uint32_t p, n, k;
  std::cout << "What is p? ";
  std::cin >> p;
  std::cout << "What is n? ";
  std::cin >> n;
  std::cout << "What is k? ";
  std::cin >> k;
  std::cout << "Probably Prime?: " << Fermat(p, n, k) << '\n';
  
  return 0;
}
