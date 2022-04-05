#include <iostream>
#include <vector>

using std::vector;
using std::cin;
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

int main() {
    long long n = 0;
    cin >> n;

    cout << fibonacci_sum_fast(n) << '\n';
    return 0;
}
