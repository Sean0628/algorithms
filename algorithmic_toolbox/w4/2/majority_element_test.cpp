#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int count_in_range(vector<int> &a, int num, int left, int right) {
  int count = 0;

  for (int i = left; i <= right; ++i) {
    if (a[i] == num) ++count;
  }

  return count;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];

  int mid = (right - left) / 2 + left;

  int leftResult = get_majority_element(a, left, mid);
  int rightResult = get_majority_element(a, mid + 1, right);

  if (leftResult == rightResult) return leftResult;

  int leftCount = count_in_range(a, leftResult, left, right);
  int rightCount = count_in_range(a, rightResult, left, right);

  if (leftCount <= (right - left) / 2 && rightCount <= (right - left) / 2) {
    return -1;
  }

  return leftCount > rightCount ? leftResult : rightResult;
}

void test_solution() {
    vector<int> pool1 { 2, 3, 9, 2, 2 };
    assert(get_majority_element(pool1, 0, pool1.size()) == 2);

    vector<int> pool2 { 1, 2, 3, 4 };
    assert(get_majority_element(pool2, 0, pool2.size()) == -1);

    vector<int> pool3 { 1, 2, 3, 1 };
    assert(get_majority_element(pool3, 0, pool3.size()) == -1);
}

int main() {
    test_solution();
    return 0;
}
