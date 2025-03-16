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

    int mn = N + 1, mx = -1;

    for (int i = 0; i < N; ++i) {
        if (i + 1 != A[i]) {
            mn = std::min(mn, i);
            mx = std::max(mx, i);
        }
    }

    if (mx == -1) {
        std::cout << "0 0" << std::endl;
    } else {
        std::reverse(A.begin() + mn, A.begin() + mx + 1);
        if (std::is_sorted(A.begin(), A.end())) {
            std::cout << mn + 1 << " " << mx + 1 << std::endl;
        } else {
            std::cout << "0 0" << std::endl;
        }
    }

    return 0;
}

