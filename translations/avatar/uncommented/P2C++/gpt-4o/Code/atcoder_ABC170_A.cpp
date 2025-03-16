#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> a;
    int number;

    while (iss >> number) {
        a.push_back(number);
    }

    for (size_t e = 0; e < a.size(); ++e) {
        if (a[e] == 0) {
            std::cout << e + 1 << std::endl;
            break;
        }
    }

    return 0;
}
// <END-OF-CODE>
