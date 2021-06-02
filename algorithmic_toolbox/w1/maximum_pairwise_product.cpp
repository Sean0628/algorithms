#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::max;

int64_t MaxPairwiseProductFast(const vector<int>& numbers) {
  int n = numbers.size();

  int index1 = 0;
  for (int i = 1; i < n; ++i) {
    if (numbers[i] > numbers[index1]) {
      index1 = i;
    }
  }

  int index2 = index1 == 0 ? 1 : 0;

  for (int i = 1; i < n; ++i) {
    if (i != index1 && numbers[i] > numbers[index2]) {
      index2 = i;
    }
  }

  return numbers[index1] * numbers[index2];
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int64_t product = MaxPairwiseProductFast(numbers);
    cout << product << "\n";

    return 0;
}
