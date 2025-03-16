#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

int next_int() {
    int value;
    std::cin >> value;
    return value;
}

std::vector<int> next_ints() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> values;
    int value;
    while (ss >> value) {
        values.push_back(value);
    }
    return values;
}

int main() {
    int n = next_int();
    double t = 0;
    for (int i = 0; i < n; ++i) {
        if ((i + 1) & 1) {
            ++t;
        }
    }
    std::cout << (t / n) << std::endl;
    return 0;
}
