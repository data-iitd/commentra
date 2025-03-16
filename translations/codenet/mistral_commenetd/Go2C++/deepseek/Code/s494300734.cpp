#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string ans = "No";

    int firstC = s.find('C');
    int lastF = s.rfind('F');

    if (firstC != std::string::npos && lastF != std::string::npos && firstC < lastF) {
        ans = "Yes";
    }

    std::cout << ans << std::endl;

    return 0;
}

