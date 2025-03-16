
#include <iostream>

int main() {
  int height, width, i;
  std::cin >> height >> width;
  char input_str[width+1];
  for(i = 0; i < width + 2; i++) {
    std::cout << "#";
  }
  std::cout << std::endl;
  for(i = 0; i < height; i++) {
    std::cin >> input_str;
    std::cout << "#" << input_str << "#" << std::endl;
  }
  for(i = 0; i < width + 2; i++) {
    std::cout << "#";
  }
  std::cout << std::endl;
  return 0;
}
