#include <algorithm>
#include <iostream>
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

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
