#include <iostream>
#include <cassert>
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

void test_solution() {
    vector<int> values1 { 3, 3, 3, 3 };
    assert(partition3(values1) == 0);

    vector<int> values2 { 40 };
    assert(partition3(values2) == 0);

    vector<int> values3 { 17, 59, 34, 57, 17, 23, 67, 1, 18, 2, 59 };
    assert(partition3(values3) == 1);

    vector<int> values4 { 1, 2, 3, 4, 5, 5, 7, 7, 8, 10, 12, 19, 25 };
    assert(partition3(values3) == 1);
}

int main() {
    test_solution();
    return 0;
}
