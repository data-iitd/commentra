#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  std::string ans = "No";

  // Find the first occurrence of 'C'
  size_t firstC = s.find('C');
  if (firstC != std::string::npos) {
    // Find the last occurrence of 'F' after the first 'C'
    size_t lastF = s.find('F', firstC + 1);
    if (lastF != std::string::npos && lastF > firstC) {
      ans = "Yes";
    }
  }

  // Check if 'C' does not appear in the string s
  if (firstC == std::string::npos) {
    ans = "No";
  }

  std::cout << ans << std::endl;
  return 0;
}

