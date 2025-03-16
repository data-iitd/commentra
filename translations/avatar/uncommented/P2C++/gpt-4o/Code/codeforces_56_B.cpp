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
        std::vector<int> newA;
        newA.insert(newA.end(), A.begin(), A.begin() + mn);
        for (int i = mx; i >= mn; --i) {
            newA.push_back(A[i]);
        }
        newA.insert(newA.end(), A.begin() + mx + 1, A.end());

        if (std::is_sorted(newA.begin(), newA.end())) {
            std::cout << mn + 1 << " " << mx + 1 << std::endl;
        } else {
            std::cout << "0 0" << std::endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
