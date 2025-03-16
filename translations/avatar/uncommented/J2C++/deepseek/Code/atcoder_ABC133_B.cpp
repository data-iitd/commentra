#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
    int N, D;
    std::cin >> N >> D;
    std::vector<std::vector<int>> vectors(N, std::vector<int>(D));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < D; ++j) {
            std::cin >> vectors[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int dist = 0;
            for (int d = 0; d < D; ++d) {
                int x = vectors[i][d] - vectors[j][d];
                dist += x * x;
            }
            double sq = std::sqrt(dist);
            answer += (std::abs(sq - std::floor(sq)) < 1e-3 ? 1 : 0);
        }
    }

    std::cout << answer << std::endl;
    return 0;
}

