#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

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

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
