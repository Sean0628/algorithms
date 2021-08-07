#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int32_t> optimal_sequence(int n) {
  vector<int32_t> minimal_steps(n + 1);
  vector<int32_t> predecessor(n + 1);

  for (int32_t i = 2; i <= n; i++) {
    minimal_steps[i] = minimal_steps[i-1] + 1;
    predecessor[i] = i - 1;

    if (i % 3 == 0) {
      if (minimal_steps[i/3] < minimal_steps[i]) {
        minimal_steps[i] = minimal_steps[i/3] + 1;
        predecessor[i] = i/3;
      }
    }

    if (i % 2 == 0) {
      if (minimal_steps[i/2] < minimal_steps[i]) {
        minimal_steps[i] = minimal_steps[i/2] + 1;
        predecessor[i] = i/2;
      }
    }
  }

  vector<int32_t> sequence;
  for (int32_t i = n; i != 0; i = predecessor[i]) {
    sequence.push_back(i);
  }

  reverse(sequence.begin(), sequence.end());
  return sequence;
}

void test_solution() {
    vector<int> result1 { 1 };
    assert(optimal_sequence(1) == result1);

    vector<int> result2 { 1, 2, 4, 5 };
    assert(optimal_sequence(5) == result2);

    vector<int> result3 { 1, 3 ,9 ,10 ,11 ,33 ,99, 297, 891, 2673, 8019, 16038, 16039, 48117, 96234 };
    assert(optimal_sequence(96234) == result3);
}

int main() {
    test_solution();
    return 0;
}
