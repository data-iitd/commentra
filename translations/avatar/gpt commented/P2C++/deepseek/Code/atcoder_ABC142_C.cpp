#include <iostream>
#include <vector>
#include <utility>  // For std::pair
#include <algorithm>  // For std::sort

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A;
    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        A.emplace_back(i + 1, value);
    }

    std::sort(A.begin(), A.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < N - 1; ++i) {
        std::cout << A[i].first << " ";
    }
    std::cout << A[N - 1].first << std::endl;

    return 0;
}
