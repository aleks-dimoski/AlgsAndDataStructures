#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>

// ----------------------------------------------------------------------

class Node {
  public:
    std::string val;
    Node* next;
    Node* prev;
    Node(std::string val="", Node* next=nullptr, Node* prev=nullptr) : val(val), next(next), prev(prev) {}
  };

class DoubleLinkedList2 {
private:
  uint32_t length;

public:
  Node* head;
  Node* tail;
  DoubleLinkedList2() : head(nullptr), tail(nullptr), length(0) {}

  void addStart(std::string val) {
    length++;
    if(head != nullptr) {
      head->prev = new Node(val, head, nullptr);
      head = head->prev;
    } else {
      head = new Node(val, nullptr, nullptr);
      tail = head;
    }
  }

  void addEnd(std::string val) {
    length++;
    if(head != nullptr) {
      tail->next = new Node(val, nullptr, tail);
      tail = tail->next;
    } else {
      head = new Node(val, nullptr, nullptr);
      tail = head;
    }
  }

  std::string removeStart() {
    std::string hold = "";
    if(head == nullptr) {
      std::cout << "\nError. LinkedList is empty.\n";
      return "";
    } else if(head->next == nullptr) {
      hold = head->val;
      head = nullptr;
    } else {
      hold = head->val;
      Node* old = head;
      head = head->next;
      head->prev = nullptr;
      delete old;
    }
    length--;
    return hold;
  }

  std::string removeEnd() {
    std::string hold = "";
    if(head == nullptr) {
      std::cout << "\nError. LinkedList is empty.\n";
      return "";
    }
    else if(head->next == nullptr) { return removeStart(); }

    Node* old = tail;
    hold = tail->val;
    tail = tail->prev;
    tail->next = nullptr;
    delete old;
    length--;
    return hold;
  }

  uint32_t size() const { return length; }

  std::string get(uint32_t i) {
    if(i > length) {throw 0;}
    Node* hold = head;
    for(uint32_t j = 0; j < i; j++)
      hold = hold->next;
    return hold->val;
  }

  friend std::ostream& operator <<(std::ostream& s, const DoubleLinkedList2& list) {
    Node* hold = list.head;
    while(hold != nullptr) { s << hold->val << " "; hold = hold->next; }
    return s;
  }
};


// ---------------------------------------------------------------------------------


class Hashmap {
private:
  uint32_t size;
  DoubleLinkedList2* data;

  uint32_t hash(const std::string& word) {
    uint32_t pos = 0;
    for(uint16_t i = 0; i < word.length(); i++) {
      pos = (pos*26 + word[i]) ^ ((pos >> 17) | (pos << 7));
    }
    return pos % size;
  }

public:
  Hashmap(uint32_t s) : size(s), data(new DoubleLinkedList2[s]) {}
  ~Hashmap() { delete [] data; }
  Hashmap(const Hashmap& h) = delete;
  Hashmap& operator =(const Hashmap& h) = delete;
  
  void add(const std::string& word) {
    uint32_t pos = hash(word);
    DoubleLinkedList2* hold = data + pos;
    hold->addEnd(word);
  }

  bool get(const std::string& word) {
    uint32_t pos = hash(word);
    DoubleLinkedList2* hold = data + pos;
    for(uint32_t i = 0; i < hold->size(); i++) {
      if(hold->get(i).compare(word) == 0) { return true; }
    }
    return false;
  }
  
  void printHist() {
    std::vector<uint32_t> hist;
    DoubleLinkedList2* hold = data;
    uint64_t total = 0;

    for(uint32_t i = 0; i < size; i++) {
      uint32_t s = hold->size();
      while(s > hist.size()) {
        hist.push_back(0);
      }
      hist[s] = hist[s]+1;
      if(i < size) { hold++; }
      total += s;
    }
    
    for(uint32_t i = 0; i < hist.size(); i++) {
      std::cout << i << ":\t" << hist[i] << '\n';
    }
    std::cout << "\nTotal number of words:\t" << total << std::endl;
    delete hold;
  }
};


// ---------------------------------------------------------------------------------


int main() {
  Hashmap m(131072);
  std::cout << std::endl;
  
  std::ifstream dict("dict.txt");
  std::string str;
  while(std::getline(dict, str)) {
    m.add(str);
  }
  
  std::regex r("[^a-zA-Z]");
  std::string line;
  
  std::ifstream doc("spell.txt");
  while(std::getline(doc, line)) {
    std::stringstream ss(line);
    while(std::getline(ss, str, ' ')) {
      str = std::regex_replace(str, r, "");
      if(!m.get(str)) {
        std::cout << str << '\n';
      }
    }
  }
  std::cout << std::endl;
  
  dict.close();
  doc.close();
  m.printHist();
    
  return 0;
}
