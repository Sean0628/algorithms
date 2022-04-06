#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using std::cout;

int fibonacci_sum_fast(long long n) {
    int num0 = 0;
    int num1 = 1;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        int remainder = n % 60;

        if (remainder == 0)
            return 0;

        for (int i = 2; i < remainder + 3; ++i) {
            int digit = (num0 + num1) % 60;
            num0 = num1;
            num1 = digit;
        }
    }

    int sum = num1 - 1;

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
