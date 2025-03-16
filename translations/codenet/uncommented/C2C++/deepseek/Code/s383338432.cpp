#include <iostream>
#include <string>

int main() {
  int height, width, i;
  std::cin >> height >> width;
  std::string input_str;
  for(i = 0; i < width + 2; i++) {
    std::cout << "#";
  }
  std::cout << "\n";
  for(i = 0; i < height; i++) {
    std::cin >> input_str;
    std::cout << "#" << input_str << "#\n";
  }
  for(i = 0; i < width + 2; i++) {
    std::cout << "#";
  }
  std::cout << "\n";
  return 0;
}
