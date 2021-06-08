#include <iostream>
#include <cassert>

long pisano(long m) {
  long prev = 0;
  long curr = 1;
  long res = 0;

  for (int i = 0; i < m * m; ++i) {
    long temp = 0;
    temp = curr;
    curr = (prev + curr) % m;
    prev = temp;

    if (prev == 0 && curr == 1)
      res = i + 1;
  }

  return res;
}

int fibonacci_modulo(int64_t a, int64_t b) {
  long pisanoPeriod = pisano(b);

  a = a % pisanoPeriod;

  long prev = 0;
  long curr = 1;

  if (a == 0)
    return 0;
  else if (a == 1)
    return 1;

  for (int i = 0; i < a - 1; ++i) {
    long temp = 0;
    temp = curr;
    curr = (prev + curr) % b;
    prev = temp;
  }

  return curr % b;
}

void test_solution() {
    assert(fibonacci_modulo(239, 1000) == 161);
    assert(fibonacci_modulo(2816213588, 239) == 151);
}

int main() {
    test_solution();
    return 0;
}
