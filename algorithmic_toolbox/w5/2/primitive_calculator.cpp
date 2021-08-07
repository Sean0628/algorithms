#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

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

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
