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
        std::string jpy = "JPY";
        std::string btc = "BTC";
        size_t jpy_pos = input.find(jpy);
        size_t btc_pos = input.find(btc);

        if (jpy_pos != std::string::npos) {
            input.replace(jpy_pos, jpy.length(), "* 1.0");
        } else if (btc_pos != std::string::npos) {
            input.replace(btc_pos, btc.length(), "* 380000.0");
        }

        std::stringstream ss(input);
        ss >> x[i];
    }

    double sum = 0.0;
    for (const auto& val : x) {
        sum += val;
    }

    std::cout << sum << std::endl;

    return 0;
}

