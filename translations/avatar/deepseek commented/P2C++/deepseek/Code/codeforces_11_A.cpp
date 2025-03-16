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
    std::getline(std::cin, input); // To consume the newline character left in the input buffer
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string item;

    while (std::getline(ss, item, ' ')) {
        x.push_back(std::stoi(item));
    }

    for (size_t a = 0; a < x.size() - 1; ++a) {
        if (x[a] >= x[a + 1]) {
            q = (x[a] - x[a + 1]) / d + 1;
            m += q;
            x[a + 1] += q * d;
        }
    }

    std::cout << m << std::endl;

    return 0;
}
