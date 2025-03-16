#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::string my_str = "";

    for (char c : s) {
        if (c == '0' || c == '1') {
            my_str += c;
        } else if (c == 'B' && !my_str.empty()) {
            my_str.pop_back();
        }
    }

    std::cout << my_str << std::endl;
    return 0;
}

// <END-OF-CODE>
