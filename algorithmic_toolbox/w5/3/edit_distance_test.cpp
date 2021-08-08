#include <iostream>
#include <cassert>

using namespace std;

int min(int x, int y, int z) {
  return min(min(x, y), z);
}

int edit_distance(const string &str1, const string &str2) {
  int m = str1.length();
  int n = str2.length();

  int table[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0) {
        table[i][j] = j;
      } else if (j == 0) {
        table[i][j] = i;
      } else if (str1[i - 1] == str2[j -1]) {
        table[i][j] = table[i - 1][j - 1];
      } else {
        table[i][j] = 1
          + min(
              table[i][j - 1],
              table[i - 1][j],
              table[i - 1][j - 1]
            );
      }
    }
  }
  return table[m][n];
}

void test_solution() {
    assert(edit_distance("ab", "ab") == 0);
    assert(edit_distance("short", "ports") == 3);
    assert(edit_distance("editing", "distance") == 5);
}

int main() {
    test_solution();
    return 0;
}
