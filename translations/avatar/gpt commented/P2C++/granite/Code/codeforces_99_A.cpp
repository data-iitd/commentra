
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string l;
    std::cin >> l;

    size_t pos = l.find('.');
    std::string s = l.substr(0, pos);
    std::string p = l.substr(pos + 1);
    int i = p[0] - '0';

    if (s[s.length() - 1] == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;
    } else if (s[s.length() - 1]!= '9' && i < 5) {
        std::cout << s << std::endl;
    } else {
        std::string s_new = s;
        s_new[s_new.length() - 1]++;
        std::cout << s_new << std::endl;
    }

    return 0;
}
