#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int fibonacci_last_digit(int n) {
    vector<int> numbers(n + 1);

    numbers[0] = 0;
    numbers[1] = 1;

    for (int i = 2; i <= n; ++i) {
      numbers[i] = (numbers[i - 1] + numbers[i - 2]) % 10;
    }

    return numbers[n];
}

int main() {
    int n = 0;
    cin >> n;

    cout << fibonacci_last_digit(n) << '\n';
    return 0;
}
