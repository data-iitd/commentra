#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::vector<double> x;

    for (int i = 0; i < N; ++i) {
        std::string input;
        std::cin >> input;
        std::stringstream ss(input);
        double value;
        std::string currency;
        ss >> value >> currency;

        if (currency == "JPY") {
            value *= 1.0;
        } else if (currency == "BTC") {
            value *= 380000.0;
        }

        x.push_back(value);
    }

    double total = 0.0;
    for (double val : x) {
        total += val;
    }

    std::cout << total << std::endl;

    return 0;
}

