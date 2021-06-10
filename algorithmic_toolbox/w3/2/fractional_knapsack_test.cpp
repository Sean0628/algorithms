#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>

using namespace std;

bool sortrev(const pair<double, int> &a, const pair<double, int> &b) {
  return (a.first > b.first);
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  vector<pair<double, int>> pairs(values.size());

  for (int idx = 0; idx < values.size(); ++idx) {
    double unitValue = (double) values[idx] / (double) weights[idx];
    pairs[idx] = make_pair(unitValue, weights[idx]);
  }

  sort(pairs.begin(), pairs.end(), sortrev);

  int remainingCapacity = capacity;
  for (int idx = 0; idx < pairs.size(); ++idx) {
    double unitValue = pairs[idx].first;
    int weight = pairs[idx].second;

    if (remainingCapacity - weight >= 0) {
      value = value + unitValue * weight;
      remainingCapacity = remainingCapacity - weight;
    } else {
      value = value + unitValue * remainingCapacity;

      remainingCapacity = 0;
    }

    if (remainingCapacity == 0)
      break;
  }

  return value;
}

void test_solution() {
    constexpr double e = 0.0001f;

    vector<int> values1 { 60, 100, 120 };
    vector<int> weights1 { 20, 50, 30 };
    assert(fabs(get_optimal_value(50, weights1, values1) - 180.0000) < e);

    vector<int> values2 { 500 };
    vector<int> weights2 { 30 };
    assert(fabs(get_optimal_value(10, weights2, values2) - 166.6667) < e);
}

int main() {
    test_solution();
    return 0;
}
