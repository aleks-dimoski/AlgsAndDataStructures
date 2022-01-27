#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Floyd Warshall distance table
double inf = 1000.0;
void FloydWarshall(uint32_t size) {

  vector<vector<double>> table;
  for(uint32_t i = 0; i < size; i++) {
    vector<double> l;
    for(uint32_t j = 0; j < size; j++) {
      l.push_back(inf);
    }
    table.push_back(l);
  }

  for(uint32_t i = 0; i < size*1.3; i++) {
    uint32_t ind1 = rand()%size;
    uint32_t ind2 = 0;
    do{ ind2 = rand()%size; } while(ind1==ind2);
    double weight = rand()%1000/1000.;
    table[ind1][ind2] = weight;
    table[ind2][ind1] = weight;
  }

  cout << "    ";
  for(uint32_t i = 0; i < size; i++) { cout << i << "     "; }
  cout << '\n';
  for(uint32_t i = 0; i < size; i++) {
    cout << i << ' ';
    for(uint32_t j = 0; j < size; j++)
      cout << ' ' << table[i][j];
    cout << '\n';
  }
  
  for(uint32_t i = 0; i < size; i++)
    for(uint32_t j = 0; j < size; j++)
      for(uint32_t k = 0; k < size; k++)
        if(table[i][k] + table[k][j] < table[i][j]) {
          table[i][j] = table[i][k] + table[k][j];
        }


  cout << "    ";
  for(uint32_t i = 0; i < size; i++) { cout << i << "     "; }
  cout << '\n';
  for(uint32_t i = 0; i < size; i++) {
    cout << i << ' ';
    for(uint32_t j = 0; j < size; j++)
      cout << ' ' << table[i][j];
    cout << '\n';
  }

}


int main() {
  FloydWarshall(5);
}

