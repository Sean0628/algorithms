#include <iostream>
#include <vector>
using std::vector;

int fibonacci_partial_sum_fast(long long from, long long to) {
    const int pisanoNum = 60;

    vector<int> fibonacci_numbers(pisanoNum);

    fibonacci_numbers[0] = 0;
    fibonacci_numbers[1] = 1;

    for (int i = 2; i <= pisanoNum; ++i) {
        fibonacci_numbers[i] =
            (fibonacci_numbers[i - 1] + fibonacci_numbers[i - 2]) % 10;
    }

    to %= pisanoNum;
    from %= pisanoNum;

    if (to < from)
      to += pisanoNum;

    int sum = 0;
    for (int i = from; i <= to; ++i) {
        sum += fibonacci_numbers[i % pisanoNum];
    }

    return sum % 10;
}

void test_solution() {
    assert(fibonacci_partial_sum_fast(3, 7) == 1);
    assert(fibonacci_partial_sum_fast(10, 10) == 5);
    assert(fibonacci_partial_sum_fast(10, 200) == 2);
    assert(fibonacci_partial_sum_fast(0, 239) == 0);
}

int main() {
    test_solution();
    return 0;
}
