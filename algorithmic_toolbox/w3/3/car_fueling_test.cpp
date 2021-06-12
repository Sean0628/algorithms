#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
  int miles = 0;
  int counter = 0;

  sort(stops.begin(), stops.end(), greater<int>());

  while (miles + tank < dist)
    for (int idx = 0; idx < stops.size(); ++idx) {
      int stop = stops[idx];

      if (stop <= miles + tank) {
        if (stop <= miles)
          return -1;

        miles = miles + (stop - miles);
        ++counter;
        break;
      }
  }

  return counter;
}

void test_solution() {
    vector<int> stops1 { 200, 375, 550, 750 };
    assert(compute_min_refills(950, 400, stops1) == 2);

    vector<int> stops2 { 1, 2, 5, 9 };
    assert(compute_min_refills(10, 3, stops2) == -1);

    vector<int> stops3 { 100, 150 };
    assert(compute_min_refills(200, 250, stops3) == 0);
}

int main() {
    test_solution();
    return 0;
}
