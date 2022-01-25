#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// LinkedList class to act as helper, and as data structure used to hold adjacencies. Nodes are labeled as integer values
class LinkedList {
private:
  uint32_t size;
  class Node {
  public:
    int32_t val;
    double weight;
    Node* next;
    Node(int32_t val=0, double weight=0., Node* next=nullptr) : val(val), next(next), weight(weight) {}
    ~Node() { delete next; }
  };
  Node* head;
public:
  LinkedList() : head(nullptr), size(0) {}
  void addStart(int32_t val, double weight) {
    size++;
    Node* a = new Node(val, weight, head);
    head = a;
  }
  void addEnd(int32_t val, double weight) {
    size++;
    if(head == nullptr) {
      addStart(val, weight);
    }
    Node* p = head;
    while(p->next != nullptr) {
      p = p->next;
    }
    p->next = new Node(val, weight, nullptr);
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
  uint32_t operator[](uint32_t a) {
    if(a > size || a < 0) { throw invalid_argument("Out-Of-Bounds Error"); }
    Node* p = head;
    for(uint32_t i = 0; i < a; i++) {
      p = p->next;
    }
    return p->val;
  }
  bool contains(uint32_t v) {
    if(head == nullptr) { return false; }
    Node* p = head;
    while(p->next != nullptr) {
      if(p->val == v) { return true; }
      p = p->next;
    }
    if(p->val == v) { return true; }
    return false;
  }
  uint32_t len() const { return size; }
  friend ostream& operator<<(ostream& s, const LinkedList& l) {
    Node* p = l.head;
    while(p != nullptr) {
      s << p->val << " " << p->weight << "  ";
      p = p->next;
    }
    return s;
  }
  
};


// Beginning of adjacency list class for BFS to operate on
class adjacencyList {
private:
  vector<LinkedList*> start;  
  
public:
  adjacencyList(uint32_t numNodes) {
    // Generates a new fully-connected graph
    for(uint32_t i = 0; i < numNodes; i++)
      start.push_back(new LinkedList());
    for(uint32_t i = 0; i < uint32_t(numNodes*1.3); i++) {
      uint32_t ind1 = rand()%numNodes;
      uint32_t ind2 = rand()%numNodes;
      if(ind1 != ind2 && !start[ind1]->contains(ind2) && !start[ind2]->contains(ind1)) {
        double weight = (rand()%1000)/1000.;
        connect(ind1, ind2, weight);
      }
    }
    for(uint32_t i = 0; i < numNodes; i++) {
      if(start[i]->len() == 0) {
        uint32_t ind;
        do {
          ind = rand()%numNodes;
        } while(ind == i);
        double weight = (rand()%1000)/1000.;
        connect(i, ind, weight);
      }
    }
  }

  void connect(uint32_t ind1, uint32_t ind2, double weight) {
    start[ind1]->addStart(ind2, weight);
    start[ind2]->addStart(ind1, weight);
  }

  friend ostream& operator <<(ostream& s, const adjacencyList& a) {
    for(uint32_t i = 0; i < a.start.size(); i++) {
      s << i << "\t" ;
      s << *(a.start[i]) << '\n';
    }
    return s;
  }

  // DFS Function
  void DFS(uint32_t v) {
    vector<bool> scheduled;
    for(uint32_t i = 0; i < start.size(); i++) { scheduled.push_back(false); }
    stack<uint32_t> upNext;
    upNext.push(v);
    scheduled[v] = true;
    while(!upNext.empty()) {
      v = upNext.top();
      upNext.pop();
      cout << v << ' ';
      for(uint32_t i = 0; i < start[v]->len(); i++) {
        uint32_t v2 = (*start[v])[i];
        if(!scheduled[v2]) {
          upNext.push(v2);
          scheduled[v2] = true;
        }
      }
    }
  }
};

int main() {
  adjacencyList g(7);
  cout << g << '\n';
  g.DFS(0);
}
