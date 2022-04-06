#include <iostream>

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

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
