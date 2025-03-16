#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

int main() {
    int N;
    long long x;
    std::cin >> N >> x;
    std::vector<long long> srimeList(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> srimeList[i];
    }

    std::vector<std::vector<long long>> costList(N, std::vector<long long>(N));
    for (int i = 0; i < N; ++i) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; ++castNum) {
            costList[i][castNum] = std::min(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }

    std::vector<long long> result(N);
    for (int i = 0; i < N; ++i) {
        long long sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += costList[j][i];
        }
        result[i] = i * x + sum;
    }

    std::cout << *std::min_element(result.begin(), result.end()) << std::endl;

    return 0;
}

