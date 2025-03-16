#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::vector<double> x(N);

    for (int i = 0; i < N; ++i) {
        std::string input;
        std::cin >> input;
        std::stringstream ss(input);
        double value;
        std::string currency;
        ss >> value >> currency;

        if (currency == "JPY") {
            x[i] = value;
        } else if (currency == "BTC") {
            x[i] = value * 380000.0;
        }
    }

    double sum = 0.0;
    for (const auto& val : x) {
        sum += val;
    }

    std::cout << sum << std::endl;

    return 0;
}
