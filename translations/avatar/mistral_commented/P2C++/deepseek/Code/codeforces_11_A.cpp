#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<int> x;
    int m = 0, q = 0;

    std::string input;
    std::getline(std::cin, input); // To consume the newline character
    std::getline(std::cin, input);
    std::istringstream stream(input);

    int num;
    while (stream >> num) {
        x.push_back(num);
    }

    for (int i = 0; i < x.size() - 1; ++i) {
        if (x[i] >= x[i + 1]) {
            q = (x[i] - x[i + 1]) / d + 1;
            m += q;
            x[i + 1] += q * d;
        }
    }

    std::cout << m << std::endl;

    return 0;
}

