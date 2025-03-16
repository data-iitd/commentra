#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> x;
    int m = 0;
    int q = 0;
    std::string input;
    std::getline(std::cin, input); // To consume the newline character
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        x.push_back(std::stoi(token));
    }
    for (size_t a = 0; a < x.size() - 1; ++a) {
        if (x[a] >= x[a + 1]) {
            q = (x[a] - x[a + 1]) / d + 1;
            m = m + q;
            x[a + 1] = x[a + 1] + q * d;
        }
    }
    std::cout << m << std::endl;
    return 0;
}
