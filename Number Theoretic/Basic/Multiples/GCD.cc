#include <iostream>
using namespace std;

uint32_t gcd(uint32_t a, uint32_t b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

int main() {
  uint32_t a,b;
  cin >> a >> b;
  cout << gcd(a, b);
  return 0;
}
