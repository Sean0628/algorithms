#include <iostream>

int get_change(int m) {
  int n = 0;
  int remaining = m;

  if (remaining / 10)
    n = n + remaining / 10;
    if (remaining != 0 && remaining % 10)
      remaining = remaining % 10;
    else
      remaining = 0;

  if (remaining / 5)
    n = n + remaining / 5;
    if (remaining != 0 && remaining % 5)
      remaining = remaining % 5;
    else
      remaining = 0;

  if (remaining / 1)
    n = n + remaining / 1;
    if (remaining != 0 && remaining % 1)
      remaining = remaining % 1;
    else
      remaining = 0;

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
