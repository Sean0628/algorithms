#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool sortrev(const pair<double,int> &a, const pair<double,int> &b) {
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

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
