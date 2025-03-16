
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

        std::stringstream ss;
        ss << input.substr(0, input.find(' ')) << " " << input.substr(input.find(' ') + 1);

        double value;
        ss >> value;

        if (input.find("JPY")!= std::string::npos) {
            value *= 1.0;
        } else if (input.find("BTC")!= std::string::npos) {
            value *= 380000.0;
        }

        x.push_back(value);
    }

    double total = 0;
    for (double val : x) {
        total += val;
    }

    std::cout << total << std::endl;

    return 0;
}
// END-OF-CODE