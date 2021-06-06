#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    vector<int> numbers(n + 1);

    numbers[0] = 0;
    numbers[1] = 1;

    for (int i = 2; i <= n; ++i) {
      numbers[i] = numbers[i - 1] + numbers[i - 2];
    }

    return numbers[n];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    test_solution();
    return 0;
}
