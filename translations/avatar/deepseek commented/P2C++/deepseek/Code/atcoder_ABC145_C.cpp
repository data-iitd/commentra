#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <tuple>
#include <iomanip>

void solve(int N, const std::vector<int>& x, const std::vector<int>& y) {
    std::vector<int> indices(N);
    std::iota(indices.begin(), indices.end(), 0);

    double total_distance = 0.0;
    int count = 0;

    do {
        double distance = 0.0;
        for (size_t i = 0; i < N - 1; ++i) {
            int f = indices[i];
            int t = indices[i + 1];
            distance += std::sqrt(std::pow(x[t] - x[f], 2) + std::pow(y[t] - y[f], 2));
        }
        total_distance += distance;
        ++count;
    } while (std::next_permutation(indices.begin(), indices.end()));

    double result = total_distance / count;
    std::cout << std::fixed << std::setprecision(10) << result << std::endl;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> x(N);
    std::vector<int> y(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> x[i] >> y[i];
    }

    solve(N, x, y);

    return 0;
}

