#include <iostream>
#include <vector>
#include <cstdlib>

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

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
