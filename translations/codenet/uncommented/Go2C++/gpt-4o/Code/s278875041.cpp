#include <iostream>
#include <string>

int main() {
    std::string a;
    std::cin >> a;

    std::string tmp = a;
    for (char &c : tmp) {
        if (c == '1') c = '0';
    }

    std::string b = tmp;
    for (char &c : b) {
        if (c == '9') c = '1';
    }

    std::string ans = b;
    for (char &c : ans) {
        if (c == '0') c = '9';
    }

    std::cout << ans << std::endl;
    return 0;
}

// <END-OF-CODE>
