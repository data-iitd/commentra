#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::string result = "";
    int i = 0;

    while (i < s.length()) {
        if (s[i] == '.') {
            result += '0';
        } else {
            i++;
            if (i < s.length() && s[i] == '.') {
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

// <END-OF-CODE>
