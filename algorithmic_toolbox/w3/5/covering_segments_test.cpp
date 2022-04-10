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

void test_solution() {
    struct Segment segment1_1 = { 1, 3 };
    struct Segment segment1_2 = { 2, 5 };
    struct Segment segment1_3 = { 3, 6 };
    vector<Segment> segments1 { segment1_1, segment1_2, segment1_3 };

    vector<int> result1 { 3 };
    assert(optimal_points(segments1) == result1);

    struct Segment segment2_1 = { 4, 7 };
    struct Segment segment2_2 = { 1, 3 };
    struct Segment segment2_3 = { 2, 5 };
    struct Segment segment2_4 = { 5, 6 };
    vector<Segment> segments2 { segment2_1, segment2_2, segment2_3, segment2_4 };

    vector<int> result2 { 3, 6 };
    assert(optimal_points(segments2) == result2);
}

int main() {
    test_solution();
    return 0;
}
