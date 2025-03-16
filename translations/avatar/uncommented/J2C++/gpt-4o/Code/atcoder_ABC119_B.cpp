#include <iostream>
#include <vector>
#include <string>
#include <numeric>

double solve(const std::vector<double>& x, const std::vector<std::string>& u) {
    double total = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        total += x[i] * (u[i] == "JPY" ? 1 : 380000);
    }
    return total;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<double> x(N);
    std::vector<std::string> u(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> x[i] >> u[i];
    }
    
    std::cout << solve(x, u) << std::endl;
    return 0;
}

// <END-OF-CODE>
