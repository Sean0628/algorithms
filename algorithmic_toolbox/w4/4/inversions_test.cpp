#include <iostream>

using namespace std;

int _merge_sort(int a[], int b[], size_t left, size_t right);
int merge(int a[], int b[], size_t left, size_t mid, size_t right);

int _merge_sort(int a[], int b[], size_t left, size_t right) {
  size_t mid, number_of_inversions = 0;

  if (right <= left) return number_of_inversions;

  mid = (left + right) / 2;

  number_of_inversions += _merge_sort(a, b, left, mid);
  number_of_inversions += _merge_sort(a, b, mid + 1, right);
  number_of_inversions += merge(a, b, left, mid + 1, right);

  return number_of_inversions;
}

int merge(int a[], int b[], size_t left, size_t mid, size_t right) {
  size_t i, j, k;
  size_t number_of_inversions = 0;

  i = left;
  j = mid;
  k = left;


  while ((i <= mid - 1) && (j <= right)) {
    if (a[i] <= a[j]) {
      b[k++] = a[i++];
    } else {
      b[k++] = a[j++];

      number_of_inversions = number_of_inversions + (mid - i);
    }
  }

  while (i <= mid - 1) {
    b[k++] = a[i++];
  }

  while (j <= right) {
    b[k++] = a[j++];
  }

  for (i = left; i <= right; ++i) {
    a[i] = b[i];
  }

  return number_of_inversions;
}

void test_solution() {
    int input[5] = { 2, 3, 9, 2, 9 };
    int sorted[5];

    assert(_merge_sort(input, sorted, 0, 5 - 1) == 2);
}

int main() {
    test_solution();
    return 0;
}
