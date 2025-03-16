
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    std::string s;

    std::cin >> s;

    for (int j = 0; j < s.length(); j++) {
        for (int i = 0; i < s.length(); i++) {
            if ((i!= j) && (s[i] == s[j])) {
                std::cout << "no" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "yes" << std::endl;

    return 0;
}

