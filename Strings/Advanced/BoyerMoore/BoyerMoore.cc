#include <iostream>

using namespace std;

int32_t BoyerMoore(const char* sub, size_t s1, const char* search, size_t s2) {
  uint32_t distTable[255];
  for(uint32_t i = 0; i < 255; i++)
    distTable[i] = s1;
  for(int16_t i = s1-1; i >= 0; i--)
    if(distTable[(int)sub[i]] == s1) { distTable[(int)sub[i]] = s1-i-1; }
  int32_t i = s1-1;
  while(i < s2) {
    int32_t jump = distTable[(int)search[i]];
    if(jump == 0) {
      bool found = true;
      for(int32_t j = i; j > i-s1 ; j--)
        if(search[j] != sub[j-i+s1-1]) { found = false; }
      if(found) { return i-s1+1; }
      jump = 1;
    }
    i += jump;
  }
  
  return -1;
}

int main() {
  char find[] = "abanana";
  size_t s1 = sizeof(find)/sizeof(char)-1;
  char str[] = "hegreata abanan abananaland";
  size_t s2 = sizeof(str)/sizeof(char)-1;
  cout << BoyerMoore(find, s1, str, s2);
  
  return 0;
}
