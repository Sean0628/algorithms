#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int k = 3;

int partition3(vector<int> &A) {
  int sum = accumulate(A.begin(), A.end(), 0);
  int m = A.size();

  if (sum % k != 0) {
    return 0;
  }

  vector<int> row(m + 1, 1);
  vector<vector<int>> table(sum / k + 1, row);

  for (int i = 1; i <= sum / k; i++) {
    table[i][0] = 0;

    for (int j = 1; j <= m; j++) {
      table[i][j] = table[i][j - 1];

      if (i >= A[j - 1]) {
        table[i][j] = table[i][j] || table[i - A[j - 1]][j - 1];
      }
    }
  }

  return table[sum / k][m];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
