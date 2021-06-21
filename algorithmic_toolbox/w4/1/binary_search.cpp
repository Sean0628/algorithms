#include <iostream>
#include <vector>

using std::vector;

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

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<long long> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
