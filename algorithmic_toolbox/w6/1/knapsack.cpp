#include <iostream>
#include <vector>

using std::vector;

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

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
