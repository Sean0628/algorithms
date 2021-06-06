#include <iostream>
#include <cassert>

using std::cout;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

long long lcm_fast(int64_t a, int64_t b) {
  return a * b / gcd(a, b);
}

void test_solution() {
    assert(lcm_fast(6, 8) == 24);
    assert(lcm_fast(761457, 614573) == 467970912861);

    assert(lcm_naive(9, 54) == lcm_fast(9, 54));
    assert(lcm_naive(29898, 189898) == lcm_fast(29898, 189898));
}

int main() {
    test_solution();
    return 0;
}
