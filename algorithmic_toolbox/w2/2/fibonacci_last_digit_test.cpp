#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int fibonacci_last_digit(int n) {
    vector<int> numbers(n + 1);

    numbers[0] = 0;
    numbers[1] = 1;

    for (int i = 2; i <= n; ++i) {
      numbers[i] = (numbers[i - 1] + numbers[i - 2]) % 10;
    }

    return numbers[n];
}

void test_solution() {
    assert(fibonacci_last_digit(3) == 2);
    assert(fibonacci_last_digit(331) == 9);
    assert(fibonacci_last_digit(327305) == 5);
}

int main() {
    test_solution();
    return 0;
}
