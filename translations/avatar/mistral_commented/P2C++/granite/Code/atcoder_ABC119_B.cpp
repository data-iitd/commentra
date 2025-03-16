
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int N;
    std::cin >> N;

    std::vector<double> x;
    for (int i = 0; i < N; i++) {
        std::string input;
        std::cin >> input;

        std::stringstream ss(input);
        std::string amount, currency;
        ss >> amount >> currency;

        double value;
        if (currency == "JPY") {
            value = std::stod(amount) * 1.0;
        } else if (currency == "BTC") {
            value = std::stod(amount) * 380000.0;
        } else {
            // Handle invalid currency
            continue;
        }

        x.push_back(value);
    }

    double sum = 0;
    for (double val : x) {
        sum += val;
    }

    std::cout << sum << std::endl;

    return 0;
}
