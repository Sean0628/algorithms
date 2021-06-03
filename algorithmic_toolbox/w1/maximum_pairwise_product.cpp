#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::sort;

int64_t MaxPairwiseProductFast(vector<int64_t>& numbers) {
  sort(numbers.begin(), numbers.end());

  return numbers.end()[-2] * numbers.end()[-1];
}

int main() {
    int n;
    cin >> n;
    vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int64_t product = MaxPairwiseProductFast(numbers);
    cout << product << "\n";

    return 0;
}
