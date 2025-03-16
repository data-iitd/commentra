#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iterator>

void solve(int N, std::vector<int>& x, std::vector<int>& y) {
    std::vector<int> indices(N);
    std::iota(indices.begin(), indices.end(), 0);
    std::vector<std::vector<int>> permutations;
    std::sort(indices.begin(), indices.end());
    do {
        permutations.push_back(indices);
    } while (std::next_permutation(indices.begin(), indices.end()));

    std::vector<double> distances;
    for (const auto& permutation : permutations) {
        double total_distance = 0.0;
        for (size_t i = 0; i < N - 1; ++i) {
            int f = permutation[i];
            int t = permutation[i + 1];
            double distance = std::sqrt(std::pow(x[t] - x[f], 2) + std::pow(y[t] - y[f], 2));
            total_distance += distance;
        }
        distances.push_back(total_distance);
    }

    double result = std::accumulate(distances.begin(), distances.end(), 0.0) / distances.size();
    std::cout << result << std::endl;
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

