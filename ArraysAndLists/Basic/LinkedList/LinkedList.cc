#include <iostream>

class LinkedList {
private:
  uint32_t size;
  class Node {
  public:
    int32_t val;
    Node* next;
    Node(int32_t val=0, Node* next=nullptr) : val(val), next(next) {}
    ~Node() { delete next; }
  };
  Node* head;
public:
  LinkedList() : head(nullptr), size(0) {}
  void addStart(int32_t val) {
    size++;
    Node* a = new Node(val, head);
    head = a;
  }
  void addEnd(int32_t val) {
    size++;
    if(head == nullptr) {
      addStart(val);
    }
    Node* p = head;
    while(p->next != nullptr) {
      p = p->next;
    }
    p->next = new Node(val, nullptr);
  }
  int32_t removeStart() {
    int32_t hold = -1;
    if(head == nullptr) {
      std::cout << "\nError. LinkedList is empty.\n";
      return -1;
    } else if(head->next == nullptr) {
      hold = head->val;
      head = nullptr;
    } else {
      hold = head->val;
      Node* n = head->next;
      head->next = head->next->next;
      head = n;
    }
    size--;
    return hold;
  }
  int32_t removeEnd() {
    Node* p = head;
    int32_t hold;
    if(head == nullptr) {
      std::cout << "\nError. LinkedList is empty.\n";
      return -1;
    }
    if(head->next == nullptr) { return removeStart(); }
    while(p->next->next != nullptr) {
      hold = p->val;
      p = p->next;
    }
    hold = p->next->val;
    p->next = nullptr;
    size--;
    return hold;
  }
};

int main() {
  uint16_t numNums;
  LinkedList a;
  std::cout << "How many nums? ";
  std::cin >> numNums;

  int32_t inp;
  for(uint16_t i = 0; i<numNums; i++) {
    std::cin >> inp;
    a.addStart(inp);
  }
  a.addEnd(7);
  
  std::cout << "Removing the first three values and then the last two." << '\n';
  std::cout << a.removeStart() << '\n';
  std::cout << a.removeStart() << '\n';
  std::cout << a.removeStart() << '\n';
  std::cout << a.removeEnd() << '\n';
  std::cout << a.removeEnd() << '\n';
}
