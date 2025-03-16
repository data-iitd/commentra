
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string l;
    std::cin >> l;

    std::vector<std::string> parts;
    size_t pos = 0;
    while ((pos = l.find('.'))!= std::string::npos) {
        parts.push_back(l.substr(0, pos));
        l.erase(0, pos + 1);
    }
    parts.push_back(l);

    std::string s = parts[0];
    std::string p = parts[1];

    char last_char = s[s.length() - 1];
    if (last_char == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;
    } else if (last_char!= '9' && std::stoi(p.substr(0, 1)) < 5) {
        std::cout << s << std::endl;
    } else {
        s[s.length() - 1] = last_char + 1;
        std::cout << s << std::endl;
    }

    return 0;
}
