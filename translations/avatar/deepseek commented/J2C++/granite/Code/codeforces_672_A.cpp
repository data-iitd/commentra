

#include <iostream>
#include <string>

std::string generateString() {
    std::string s;
    for (int i = 1; i <= 1000; i++) {
        s += std::to_string(i);
    }
    return s;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << generateString()[n - 1] << std::endl;
    return 0;
}

