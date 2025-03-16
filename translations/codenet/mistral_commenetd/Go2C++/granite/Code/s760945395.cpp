

#include <iostream>

int main() {
  for (int i = 0; i < 5; i++) {
    int a;
    std::cin >> a;
    if (a == 0) {
      std::cout << i + 1 << std::endl;
    }
  }
  return 0;
}
