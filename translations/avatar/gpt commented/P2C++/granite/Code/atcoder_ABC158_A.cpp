
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string result = "No";
    if (s.find("A")!= std::string::npos && s.find("B")!= std::string::npos) {
        result = "Yes";
    }

    std::cout << result << std::endl;

    return 0;
}

