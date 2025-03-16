#include <iostream>
#include <vector>
#include <string>
#include <numeric> // for std::accumulate

int main() {
    int N;
    std::cin >> N;
    std::vector<double> x(N);
    std::vector<std::string> u(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> x[i] >> u[i];
    }

    double result = solve(x, u);
    std::cout << result << std::endl;

    return 0;
}

double solve(const std::vector<double>& x, const std::vector<std::string>& u) {
    double sum = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        if (u[i] == "JPY") {
            sum += x[i];
        } else if (u[i] == "BTC") {
            sum += x[i] * 380000.0;
        }
    }
    return sum;
}
