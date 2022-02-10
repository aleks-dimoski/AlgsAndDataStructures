#include <iostream>


template <class T>
class DoubleLinkedList {
private:
  uint32_t length;
  
  class Node {
  public:
    T val;
    Node* next;
    Node* prev;
    Node(T val, Node* next=nullptr, Node* prev=nullptr) : val(val), next(next), prev(prev) {}
    void deleteChain() {
      if(next != nullptr)
        next->deleteChain();
      delete next;
    }
  };

public:
  Node* head;
  Node* tail;
  DoubleLinkedList() : head(nullptr), tail(nullptr), length(0) {}
  ~DoubleLinkedList() {
    if(head != nullptr)
      head->deleteChain();
    delete head;
  }

  void addStart(T val) {
    length++;
    if(head != nullptr) {
      head->prev = new Node(val, head, nullptr);
      head = head->prev;
    } else {
      head = new Node(val, nullptr, nullptr);
      tail = head;
    }
  }

  void addEnd(T val) {
    length++;
    if(head != nullptr) {
      tail->next = new Node(val, nullptr, tail);
      tail = tail->next;
    } else {
      head = new Node(val, nullptr, nullptr);
      tail = head;
    }
  }

  T removeStart() {
    T hold;
    if(head == nullptr) {
      std::cout << "\nError. LinkedList is empty.\n";
      return -1;
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

  T removeEnd() {
    T hold;
    if(head == nullptr) {
      std::cout << "\nError. LinkedList is empty.\n";
      return -1;
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

  friend std::ostream& operator <<(std::ostream& s, const DoubleLinkedList& list) {
    Node* hold = list.head;
    while(hold != nullptr) { s << hold->val << " "; hold = hold->next; }
    return s;
  }
};

int main() {
    DoubleLinkedList<uint32_t> mylist;

    for (int i = 0; i < 10; i++)
      mylist.addEnd(i);
    for (int i = 0; i < 10; i++)
      mylist.addStart(i);
    for (int i = 0; i < 5; i++)
      mylist.removeEnd();
    std::cout << mylist << '\n';
    std::cout << mylist.size();
}
