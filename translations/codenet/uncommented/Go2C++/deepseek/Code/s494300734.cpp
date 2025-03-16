#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  
  std::string ans = "No";
  size_t firstC = s.find('C');
  size_t lastF = s.rfind('F');
  
  if (firstC != std::string::npos && firstC < lastF) {
    ans = "Yes";
  }
  
  std::cout << ans << std::endl;
}

