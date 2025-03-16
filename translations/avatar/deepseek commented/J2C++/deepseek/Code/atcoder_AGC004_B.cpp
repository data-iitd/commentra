#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::accumulate

int main() {
    int N;
    long long x;
    std::cin >> N;
    std::cin >> x;

    std::vector<long long> srimeList(N);
    for (int i = 0; i < N; i++) {
        std::cin >> srimeList[i];
    }

    std::vector<std::vector<long long>> costList(N, std::vector<long long>(N));
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i];
        for (int castNum = 1; castNum < N; castNum++) {
            int index = (i - castNum + N) % N;
            costList[i][castNum] = std::min(costList[i][castNum - 1], srimeList[index]);
        }
    }

    std::vector<long long> result(N);
    for (int i = 0; i < N; i++) {
        long long costSum = 0;
        for (int j = 0; j < N; j++) {
            costSum += costList[j][i];
        }
        result[i] = i * x + costSum;
    }

    long long minCost = *std::min_element(result.begin(), result.end());
    std::cout << minCost << std::endl;

    return 0;
}
