#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void partition3(vector<int> &a, int l, int r, int& i, int& j) {
  if (r - l <= 1) {
    if (a[r] < a[l])
      swap(a[r], a[l]);

    i = l;
    j = r;
    return;
  }

  int mid = l;
  int pivot = a[r];

  while (mid <= r) {
    if (a[mid] < pivot)
      swap(a[l++], a[mid++]);
    else if (a[mid] == pivot)
      ++mid;
    else if (a[mid] > pivot)
      swap(a[mid], a[r--]);
  }

  i = l - 1;
  j = mid;
}

void quick_sort(vector<int> &a, int l, int r) {
  if (l >= r)
    return;

  int i, j;

  partition3(a, l, r, i, j);

  quick_sort(a, l, i);
  quick_sort(a, j, r);
}

void test_solution() {
    vector<int> input1 { 2, 3, 9, 2, 2 };
    vector<int> expected1 { 2, 2, 2, 3, 9 };

    quick_sort(input1, 0, input1.size() - 1);
    assert(input1 == expected1);

    vector<int> input2 { 2 };
    vector<int> expected2 { 2 };

    quick_sort(input2, 0, input2.size() - 2);
    assert(input2 == expected2);
}

int main() {
    test_solution();
    return 0;
}
