#include <iostream>
using namespace std;

uint32_t fibonacci(uint32_t n) {
  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;

  uint32_t hold = 0;
  uint32_t cur = 1;
  for(uint32_t i = 0; i < n; i++) {
    cur = hold + cur;
    hold = cur - hold;
  }

  return cur;
}

int main() {
  uint32_t num;
  cin >> num;
  
  cout << fibonacci(num);
  return 0;
}
