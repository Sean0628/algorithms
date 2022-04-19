#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    for (int k = n, l = 1; k > 0; ++l) {
        if (k <= 2 * l) {
            summands.push_back(k);
            k -= k;
        } else {
            summands.push_back(l);
            k -= l;
        }
    }

    return summands;
}

void test_solution() {
    vector<int> result1 { 1, 2, 3 };
    assert(optimal_summands(6) == result1);

    vector<int> result2 { 1, 2, 5 };
    assert(optimal_summands(8) == result2);

    vector<int> result3 { 2 };
    assert(optimal_summands(2) == result3);
}

int main() {
    test_solution();
    return 0;
}
