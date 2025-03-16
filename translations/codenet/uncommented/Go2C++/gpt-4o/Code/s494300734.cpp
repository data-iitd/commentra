#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string ans = "No";
    size_t indexC = s.find('C');
    size_t lastIndexF = s.rfind('F');

    if (indexC != std::string::npos && indexC < lastIndexF) {
        ans = "Yes";
    }
    if (indexC == std::string::npos) {
        ans = "No";
    }

    std::cout << ans << std::endl;
    return 0;
}

// <END-OF-CODE>
