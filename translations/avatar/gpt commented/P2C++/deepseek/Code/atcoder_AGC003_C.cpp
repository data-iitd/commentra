#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        A[i] = value * N + i;
    }

    std::sort(A.begin(), A.end());

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int d = (A[i] % N) % 2;
        if (d % 2 != i % 2) {
            ++cnt;
        }
    }

    std::cout << cnt / 2 << std::endl;

    return 0;
}
