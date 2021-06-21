#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search(const vector<long long> &a, int x) {
  int left = 0, right = (int)a.size();

  while (right >= left) {
    int mid = (left + right) / 2;

    if (a[mid] == x) {
      return mid;
    } else if (a[mid] > x) {
      right = mid - 1;
    } else if (a[mid] < x) {
      left = mid + 1;
    }
  }

  return -1;
}

int linear_search(const vector<long long> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

void test_solution() {
    vector<long long> pool1 { 1, 5, 8, 12, 13 };
    vector<long long> target1 { 1, 8, 1, 23, 1, 11 };

    for (int i = 0; i < target1.size(); ++i) {
      assert(binary_search(pool1, target1[i]) == linear_search(pool1, target1[i]));
    }

    vector<long long> pool2 { 1, 2, 3, 4, 5 };
    vector<long long> target2 { 1, 2, 3, 4, 5 };

    for (int i = 0; i < target2.size(); ++i) {
      assert(binary_search(pool2, target2[i]) == linear_search(pool2, target2[i]));
    }

    vector<long long> pool3 { 0, 1, 3, 4, 5 };
    vector<long long> target3 { 0, 2, 3, 4, 5 };

    for (int i = 0; i < target3.size(); ++i) {
      assert(binary_search(pool3, target3[i]) == linear_search(pool3, target3[i]));
    }
}

int main() {
    test_solution();
    return 0;
}
