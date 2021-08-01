#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int> denominations { 1, 3, 4 };

int get_change(int m) {
  vector<int> table(m + 1, m + 1);

  table[0] = 0;

  for (int i = 0; i < denominations.size(); i++) {
    for (int j = 0; j < table.size(); j++) {
      if (denominations[i] <= j) {
        table[j] = min(table[j], table[j-denominations[i]] + 1);
      }
    }
  }

  return table[m] == (m + 1) ? - 1 : table[m];
}

void test_solution() {
    assert(get_change(2) == 2);
    assert(get_change(6) == 2);
    assert(get_change(4) == 1);
    assert(get_change(34) == 9);
}

int main() {
    test_solution();
    return 0;
}
