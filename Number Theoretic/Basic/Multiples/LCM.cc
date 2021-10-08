#include <iostream>
using namespace std;

uint32_t gcd(uint32_t a, uint32_t b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

uint32_t lcm(uint32_t a, uint32_t b) {
  return (a*b)/gcd(a, b);
}

int main() {
  uint32_t a, b;
  cin >> a >> b;
  cout << lcm(a, b);
}
