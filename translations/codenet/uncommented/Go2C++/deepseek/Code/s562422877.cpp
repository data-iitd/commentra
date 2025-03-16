#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 1; i < N; ++i) {
        ans += A[i] - A[i - 1];
    }

    std::cout << ans << std::endl;

    return 0;
}
