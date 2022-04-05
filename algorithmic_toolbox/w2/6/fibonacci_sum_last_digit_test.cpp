#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using std::cout;

long long fibonacci_sum_fast(long long n) {
    long long num0 = 0;
    long long num1 = 1;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        long long remainder = n % 60;

        if (remainder == 0)
          return 0;

        for (long long i = 2; i < remainder + 3; ++i) {
          long long digit = (num0 + num1) % 60;
          num0 = num1;
          num1 = digit;
        }
    }

    long long sum = num1 - 1;

    return sum % 10;
}

void test_solution() {
    assert(fibonacci_sum_fast(0) == 0);
    assert(fibonacci_sum_fast(3) == 4);
    assert(fibonacci_sum_fast(100) == 5);
    assert(fibonacci_sum_fast(614162383528) == 9);
}

int main() {
    test_solution();
    return 0;
}
