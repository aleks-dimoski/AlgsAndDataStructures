#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <ctype.h>
#include <stdio.h>

class Trie {
private:
  class Node2 {
  public:
    std::vector<Node2*> al;
    bool end;
    Node2() : end(false) {
      for(uint8_t i = 0; i < 26; i++)
        al.push_back(nullptr);
    }
  };
  Node2* root;
  uint64_t numNodes;

public:
  Trie() : root(new Node2()), numNodes(0) {}
  ~Trie() { delete root; }
  Trie(const Trie& h) = delete;
  Trie& operator =(const Trie& h) = delete;
  
  void add(const std::string& word) {
    Node2* cur = root;
    for(uint16_t i = 0; i < word.length(); i++) {
      uint16_t ind = uint16_t(tolower(word.at(i))) - uint16_t('a');
      if(cur->al[ind] == nullptr) {
        cur->al[ind] = new Node2();
        numNodes++;
      }
      cur = cur->al[ind];
    }
    cur->end = true;
  }

  bool get(const std::string& word) {
    Node2* cur = root;
    for(uint16_t i = 0; i < word.length(); i++) {
      uint16_t ind = uint16_t(tolower(word.at(i))) - uint16_t('a');
      if(cur->al[ind] == nullptr)
        return false;
      cur = cur->al[ind];
    }
    return(cur->end);
  }
  uint64_t size() { return numNodes; }

};


int main() {
  Trie t;
  std::cout << std::endl;
  
  std::ifstream dict("dict.txt");
  std::string str;
  while(std::getline(dict, str)) {
    t.add(str);
  }
  
  std::regex r("[^a-zA-Z]");
  std::string line;
  
  std::ifstream doc("spell.txt");
  while(std::getline(doc, line)) {
    std::stringstream ss(line);
    while(std::getline(ss, str, ' ')) {
      str = std::regex_replace(str, r, "");
      if(!t.get(str)) {
        std::cout << str << '\n';
      }
    }
  }
  std::cout << std::endl;
  
  dict.close();
  doc.close();
  std::cout << t.size();
  
  return 0;
}
