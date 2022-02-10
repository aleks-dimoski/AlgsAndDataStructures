#include <iostream>
using namespace std;

class Stack {
private:
  class Node {
  public:
    Node* next;
    int32_t val;
    Node(int32_t val, Node* next) {
      this->val = val;
      this->next = next;
    }
    ~Node() { delete next; }
  };
public:
  Node* head;
  Stack() : head(nullptr) {}
  void push(int32_t val) {
    if(head == nullptr) {
      head = new Node(val, nullptr);
    } else {
      Node* p = new Node(0, nullptr);
      p->next = head;
      p->val = val;
      head = p;
    }
  }
  int32_t pop() {
    if(head == nullptr)
      return 0;
    int32_t num = head->val;
    head = head->next;
    return num;
  }
  
};

int main() {
  Stack s;
  uint16_t qty = 0;
  cin >> qty;
  for(int i = 0; i < qty; i++) {
    uint32_t inp;
    cin >> inp;
    s.push(inp);
  }
  for(int i = 0; i < qty; i++)
    cout << s.pop() << " ";
  return 0;
}
