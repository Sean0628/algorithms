#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool is_greater_or_equal(string digit, string max_digit) {
  return std::stoi(digit + max_digit) >= std::stoi(max_digit + digit);
}

string largest_number(vector<string> a) {
  string result;
  std::stringstream ret;

  while (a.size()) {
    string max_digit = "0";
    int index = 0;

    for (int i = 0; i < a.size(); ++i) {
      string digit = a[i];
      if (is_greater_or_equal(digit, max_digit)) {
        max_digit = digit;
        index = i;
      }

    }
    result += max_digit;
    a.erase(a.begin() + index);
  }

  return result;
}

void test_solution() {
    vector<string> input1 { "21", "2" };
    assert(largest_number(input1) == "221");

    vector<string> input2 { "9", "4", "6", "1", "9" };
    assert(largest_number(input2) == "99641");

    vector<string> input3 { "23", "39", "92" };
    assert(largest_number(input3) == "923923");
}

int main() {
    test_solution();
    return 0;
}
