#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int N, X;
    std::cin >> N >> X;

    if (X == 1 || X == N * 2 - 1) {
        std::cout << "No" << std::endl;
        return 0;
    }

    std::cout << "Yes" << std::endl;

    std::vector<int> xs;
    if (X == N * 2 - 2) {
        for (int i = N - 1; i <= X + 1; ++i) {
            xs.push_back(i);
        }
        for (int i = 1; i < N - 1; ++i) {
            xs.push_back(i);
        }
    } else {
        std::vector<int> ys;
        for (int i = 1; i < X - 1; ++i) {
            ys.push_back(i);
        }
        for (int i = X + 3; i <= N * 2; ++i) {
            ys.push_back(i);
        }
        ys.insert(ys.begin() + N - 3, X + 2);
        ys.insert(ys.begin() + N - 2, X - 1);
        ys.insert(ys.begin() + N - 1, X);
        ys.insert(ys.begin() + N, X + 1);
        xs = ys;
    }

    for (int x : xs) {
        std::cout << x << std::endl;
    }

    return 0;
}
