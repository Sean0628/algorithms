#include <iostream>
#include <vector>

using std::vector;
using std::cin;
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

int main() {
    long long n = 0;
    cin >> n;

    cout << fibonacci_sum_fast(n) << '\n';
    return 0;
}
