#include <iostream>

int main (void) {
  int A, B, C;

  std::cin >> A >> B >> C;

  if (A < C && C < B) {
    std::cout << "Yes\n";
  } else if (A > C && C > B) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}

