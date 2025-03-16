
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::tuple<int, int>> A;
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        A.push_back(std::make_tuple(i + 1, x));
    }

    std::sort(A.begin(), A.end(), [](const std::tuple<int, int>& a, const std::tuple<int, int>& b) {
        return std::get<1>(a) < std::get<1>(b);
    });

    for (int i = 0; i < N - 1; i++) {
        std::cout << std::get<0>(A[i]) << " ";
    }
    std::cout << std::get<0>(A[N - 1]) << std::endl;

    return 0;
}
