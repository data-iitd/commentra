#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::vector<int> a;
    std::string token;

    while (std::getline(iss, token, ' ')) {
        a.push_back(std::stoi(token));
    }

    for (int e = 0; e < a.size(); ++e) {
        if (a[e] == 0) {
            std::cout << e + 1 << std::endl;
            break;
        }
    }

    return 0;
}
