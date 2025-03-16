#include <iostream>
#include <string>

int main() {
    std::string ip;
    std::cin >> ip;
    std::string st = "";

    if (ip.length() != 1) {
        if (ip[0] == '9') {
            st = "9";
            ip = ip.substr(1);
        }
        for (char i : ip) {
            if (i > '4') {
                int n = 9 - (i - '0');
                st += std::to_string(n);
            } else {
                st += i;
            }
        }
    } else {
        st = ip;
    }

    std::cout << std::stoi(st) << std::endl;

    return 0;
}

// <END-OF-CODE>
