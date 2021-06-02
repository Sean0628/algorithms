#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::max;

int64_t MaxPairwiseProductNaive(const vector<int>& numbers) {
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

void PrintVector (const vector<int>& input) {
  for (int i = 0; i < input.size(); ++i) {
    cout << input.at(i) << " ";
  }

  cout << "\n";
}

void StressTest(int n, int m) {

  while (true) {
    int n = rand() % 10 + 2;
    vector<int> a;
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
