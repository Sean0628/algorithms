#include <iostream>
#include <vector>
using std::vector;

int fibonacci_sum_squares_fast(long long n) {
    int num0 = 0;
    int num1 = 1;

    if (n <= 1)
        return n;
    else {
        int remainder = n % 60;

        if (remainder == 0)
            return 0;

        for (int i = 2; i < remainder + 2; ++i) {
            int digit = (num0 + num1) % 60;
            num0 = num1;
            num1 = digit;
        }
    }
    int sum = num0 * num1;

    return sum % 10;
}

void test_solution() {
    assert(fibonacci_sum_squares_fast(7) == 3);
    assert(fibonacci_sum_squares_fast(73) == 1);
    assert(fibonacci_sum_squares_fast(1234567890) == 0);
}

int main() {
    test_solution();
    return 0;
}
