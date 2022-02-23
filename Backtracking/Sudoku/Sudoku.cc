#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <set>
#include <vector>

using namespace std;

class Board {
 private:
  vector<vector<uint16_t>> board;
  set<uint16_t> possible = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  // default_random_engine rng;

 public:
  Board() {
    for (uint16_t i = 0; i < 9; i++) {
      vector<uint16_t> tmp;
      for (uint16_t j = 0; j < 9; j++) {
        tmp.push_back(0);
      }
      board.push_back(tmp);
    }

    generate_diagonals();
    generate_solution();
  }

  void generate_diagonals() {
    vector<uint16_t> vals = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (uint16_t i = 0; i < 3; i++) {
      random_shuffle(vals.begin(), vals.end());
      for (uint16_t y = 0; y < 3; y++)
        for (uint16_t x = 0; x < 3; x++)
          board[i * 3 + y][i * 3 + x] = vals[y * 3 + x];
    }
  }

  bool generate_solution(uint16_t i = 0) {
    uint16_t y = i / 9;
    uint16_t x = i % 9;
    vector<uint16_t> vals;
    if (i == 9 * 9 - 1) {
      return true;
    } else if (i < 9 * 9 - 1) {
      if (board[y][x] == 0) {
        vals = get_valid(y, x);
        do {
          board[y][x] = 0;
          if (vals.size() == 0) {
            return false;
          }
          board[y][x] = vals[0];
          vals.erase(vals.begin());
        } while (!generate_solution(i + 1));
        return true;
      } else {
        return generate_solution(i + 1);
      }
    }
    return false;
  }

  void check_square() {}

  vector<uint16_t> get_valid(uint16_t y, uint16_t x) {
    set<uint16_t> s;
    s.insert(board[y][x]);

    for (uint16_t i = 0; i < 9; i++) {
      if (i != x) s.insert(board[y][i]);
      if (i != y) s.insert(board[i][x]);
    }

    uint16_t quad_x = x / 3;
    uint16_t quad_y = y / 3;

    for (uint16_t i = quad_y * 3; i < quad_y * 3 + 3; i++)
      for (uint16_t j = quad_x * 3; j < quad_x * 3 + 3; j++)
        if (i != y && j != x) s.insert(board[i][j]);

    set<uint16_t> result;
    set_difference(possible.begin(), possible.end(), s.begin(), s.end(),
                   inserter(result, result.end()));

    vector<uint16_t> output;
    copy(result.begin(), result.end(), back_inserter(output));

    return output;
  }

  friend ostream& operator<<(ostream& s, const Board& b) {
    for (uint16_t i = 0; i < 9; i++) {
      for (uint16_t j = 0; j < 9; j++) {
        s << b.board[i][j] << '\t';
      }
      s << '\n';
    }
    return s;
  }
};

int main() {
  Board b;
  cout << '\n' << b << endl;

  return 0;
}
