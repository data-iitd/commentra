#include <iostream>
#include <vector>
#include <string>
#include <numeric> // for std::accumulate

int main() {
    std::string n;
    std::vector<std::string> a = { "10", "100", "1000", "10000", "100000" };
    std::cin >> n;
    int new_value = std::accumulate(n.begin(), n.end(), 0, [](int sum, char c) { return sum + (c - '0'); });
    if (std::find(a.begin(), a.end(), n) != a.end()) {
        std::cout << 10 << std::endl;
    } else {
        std::cout << new_value << std::endl;
    }
    return 0;
}

