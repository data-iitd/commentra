#include <iostream>
#include <string>

int main() {
    std::string s;
    std::string result;
    int i = 0;

    std::cin >> s;

    while (i < s.length()) {
        if (s[i] == '.') {
            result += '0';
        } else {
            i++;
            if (s[i] == '.') {
                result += '1';
            } else {
                result += '2';
            }
        }
        i++;
    }

    std::cout << result << std::endl;

    return 0;
}

