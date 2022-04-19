#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (int i = 0; i < a.size(); ++i) {
    result += (long long) a[i] * b[i];
  }

  std::cout << result << "\n";
  return result;
}

void test_solution() {
    vector<int> a1 { 23 };
    vector<int> b1 { 39 };
    assert(max_dot_product(a1, b1) == 897);

    vector<int> a2 { 1, 3, -5 };
    vector<int> b2 { -2, 4, 1 };
    assert(max_dot_product(a2, b2) == 23);

    vector<int> a3 { 2, 3, 9 };
    vector<int> b3 { 7, 4, 2 };
    assert(max_dot_product(a3, b3) == 79);
}

int main() {
    test_solution();
    return 0;
}
