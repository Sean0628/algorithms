#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using std::cout;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd_fast(b, a % b);
  }
}

void test_solution() {
    assert(gcd_fast(18, 35) == 1);
    assert(gcd_fast(28851538, 1183019) == 17657);

    assert(gcd_naive(9, 54) == gcd_fast(9, 54));
    assert(gcd_naive(29898, 189898) == gcd_fast(29898, 189898));
}

int main() {
    test_solution();
    return 0;
}
