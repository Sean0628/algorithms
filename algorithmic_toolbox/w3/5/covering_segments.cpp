#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool compareByEnd(const Segment &a, const Segment &b) {
  return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  sort(segments.begin(), segments.end(), compareByEnd);

  int point = segments[0].end;
  points.push_back(point);

  for (int i = 1; i < segments.size(); ++i) {
    if (point < segments[i].start || point > segments[i].end) {
      point = segments[i].end;
      points.push_back(point);
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
