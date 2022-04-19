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

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
