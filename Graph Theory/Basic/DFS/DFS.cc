#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool increasing(uint32_t a, uint32_t b) { return a<b; }

class CSRGraph {
private:
  uint32_t numNodes;
  vector<uint32_t> start;
  vector<uint32_t> adjacency;
  vector<double> w;

public:
  CSRGraph(uint32_t numNodes, uint32_t numCon) : numNodes(numNodes) {
    for(uint32_t i = 0; i < numNodes; i++)
      start.push_back(i);
    for(uint32_t i = 0; i < numCon-numNodes; i++)
      start.push_back(1+rand()%numNodes);
    sort(start.begin(), start.end(), increasing);
    for(uint32_t i = 0; i < numCon; i++) {
      uint32_t newAdjacency = 0;
      do {
        newAdjacency = 1+rand()%numNodes;
      } while(newAdjacency == start[i]);
      adjacency.push_back(newAdjacency);
      w.push_back(1.*(rand()%1000)/1000);
    }
  }
  
  friend ostream& operator <<(ostream& s, const CSRGraph& g) {
    for(uint32_t i = 0; i < g.start.size(); i++) {
      s << g.start[i] << '\t' << g.adjacency[i] << '\t' << g.w[i] << '\n';
    }
    return s;
  }
  
  vector<uint32_t> adjacent(uint32_t v) {
    vector<uint32_t> ad;
    for(uint32_t i = v; start[i] <= v && i < adjacency.size(); i++)
      if(start[i] == v) { ad.push_back(adjacency[i]); }
    return ad;
  }
  
  void dfs(uint32_t v) {
    vector<bool> scheduled;
    for(uint32_t i = 0; i < numNodes; i++)
      scheduled.push_back(false);
    stack<uint32_t> nodes;
    nodes.push(v);
    scheduled[v] = true;
    while(!nodes.empty()) {
      v = nodes.top();
      nodes.pop();
      cout << v << '\n';
      vector<uint32_t> adj = adjacent(v);
      for(uint32_t v2 : adj) {
        cout << v2 << '\t';
        if(!scheduled[v2]) {
          nodes.push(v2);
          scheduled[v2] = true;
        }
        cout << '\n';
      }
    }
  }
  
};

int main() {
  CSRGraph g(5, 8);
  cout << g;
  g.dfs(0);
  
}
