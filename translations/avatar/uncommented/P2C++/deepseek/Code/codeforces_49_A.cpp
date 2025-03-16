#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string a;
    std::vector<char> vo = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    std::getline(std::cin, a);
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] == ' ' || a[i] == '?') {
            continue;
        } else {
            if (std::find(vo.begin(), vo.end(), a[i]) != vo.end()) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
            break;
        }
    }
    return 0;
}

