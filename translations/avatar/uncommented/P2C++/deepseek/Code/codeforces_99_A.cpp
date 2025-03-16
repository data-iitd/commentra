#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string l;
    std::getline(std::cin, l);
    std::vector<std::string> l_split;
    std::stringstream ss(l);
    std::string item;

    while (std::getline(ss, item, '.')) {
        l_split.push_back(item);
    }

    std::vector<char> s(l_split[0].begin(), l_split[0].end());
    std::vector<char> p(l_split[1].begin(), l_split[1].end());
    int i = p[0] - '0';

    if (s[s.size() - 1] == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;
    } else if (s[s.size() - 1] != '9' && i < 5) {
        std::string s_str(s.begin(), s.end());
        std::cout << s_str << std::endl;
    } else {
        std::string s_str(s.begin(), s.end());
        int num = std::stoi(s_str) + 1;
        std::cout << std::to_string(num) << std::endl;
    }

    return 0;
}

