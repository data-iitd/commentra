#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    std::vector<int> a;
    int num;

    while (iss >> num) {
        a.push_back(num);
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 0) {
            std::cout << i + 1 << std::endl;
            break;
        }
    }

    return 0;
}
