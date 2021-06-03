#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::sort;

int64_t MaxPairwiseProductNaive(const vector<int64_t>& numbers) {
    int64_t product = 0;
    int n = numbers.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          int64_t num = numbers[i] * numbers[j];
          product = (product > num) ? product : num;
        }
    }

    return product;
}

int64_t MaxPairwiseProductFast(vector<int64_t>& numbers) {
  sort(numbers.begin(), numbers.end());

  return numbers.end()[-2] * numbers.end()[-1];
}

void PrintVector(const vector<int64_t>& input) {
  for (int i = 0; i < input.size(); ++i) {
    cout << input.at(i) << " ";
  }

  cout << "\n";
}

void StressTest(int n, int m) {

  while (true) {
    int n = rand() % 10 + 2;
    vector<int64_t> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(rand() % 100000);
    }

    PrintVector(a);

    int64_t result1 = MaxPairwiseProductNaive(a);
    int64_t result2 = MaxPairwiseProductFast(a);

    if (result1 == result2) {
      cout << "OK\n";
    } else {
      cout << "Wrong answer: " << result1 << " " << result2 << "\n";
      break;
    }
  }
}

int main() {
  StressTest(10, 100000);

  return 0;
}
