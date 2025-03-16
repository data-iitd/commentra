#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::vector<double> x(N);
    std::string input;
    
    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, input);
        std::stringstream ss(input.replace(input.find("JPY"), 3, "* 1.0").replace(input.find("BTC"), 3, "* 380000.0"));
        ss >> x[i];
    }
    
    double sum = 0.0;
    for (const auto& val : x) {
        sum += val;
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}
