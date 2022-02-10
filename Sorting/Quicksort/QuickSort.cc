#include <iostream>
#include <stdlib.h>

uint32_t partition(int32_t* x, uint32_t L, uint32_t R) {
  uint32_t ind = rand()%(R-L) + L;
  int32_t pivot = x[ind];
  uint32_t i = L;
  uint32_t j = R;
  
  std::cout << "\n" << pivot << " " << ind << "\n";
  
  while(i < j) {
    while(i < j && x[i] < pivot)
      i++;
    while(i < j && x[j] > pivot)
      j--;
  
    if(i < j) {
      x[i] = x[i]+x[j];
      x[j] = x[i]-x[j];
      x[i] = x[i]-x[j];
    }
  }
  
  for(uint16_t i = 0; i < 10; i++)
    std::cout << x[i] << " ";
  std::cout << std::endl;
  
  return j;
}

void quicksort(int32_t* x, uint32_t L, uint32_t R) {  
  uint32_t ind = partition(x, L, R);
  
  if(ind > L) {
    quicksort(x, L, ind);
  }
  if(ind+1 < R) {
    quicksort(x, ind+1, R);
  }
}

int main() {
  int32_t x[10] = {1, 5, 2, 6, 0, 9, -12, 8, 3, 4};
  
  std::cout << "Running" << std::endl;
  for(int32_t val : x)
    std::cout << val << " ";
  std::cout << std::endl;
  
  quicksort(x, 0, 9);
  
  for(int32_t val : x)
    std::cout << val << " ";
  std::cout << std::endl;
  
  return 0;
}
