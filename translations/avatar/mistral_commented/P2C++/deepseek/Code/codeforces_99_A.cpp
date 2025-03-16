#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string l;
    std::cin >> l;

    std::vector<std::string> parts = split(l, '.');
    std::string s = parts[0];
    std::string p = parts[1];

    char last_char = s.back();

    if (last_char == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;
    } else if (last_char != '9' && std::stoi(p.substr(0, 1)) < 5) {
        std::cout << s << std::endl;
    } else {
        int num = std::stoi(s) + 1;
        std::cout << num << std::endl;
    }

    return 0;
}
