
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string result = "";

    for (int i = 0; i < s.length(); i++) {
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
    }

    std::cout << result << std::endl;

    return 0;
}
