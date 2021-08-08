#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  vector<int> weights { 0 };
  weights.insert(weights.end(), w.begin(), w.end());

  int m = weights.size();

  vector<int> row(W + 1, 0);
  vector<vector<int>> table(m, row);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= W; j++) {
      if (i == 0 || j == 0) {
        table[i][j] = 0;
        continue;
      }

      table[i][j] = table[i - 1][j];

      if (weights[i] <= j) {
        int value = table[i - 1][j - weights[i]] + weights[i];

        if (table[i][j] < value) {
          table[i][j] = value;
        }
      }
    }
  }

  return table[m - 1][W];
}

void test_solution() {
    int limit1 = 10;
    vector<int> weights1 { 1, 4, 8 };
    assert(optimal_weight(limit1, weights1) == 9);

    int limit2 = 10;
    vector<int> weights2 { 3, 5, 3, 3, 5 };
    assert(optimal_weight(limit2, weights2) == 10);
}

int main() {
    test_solution();
    return 0;
}
