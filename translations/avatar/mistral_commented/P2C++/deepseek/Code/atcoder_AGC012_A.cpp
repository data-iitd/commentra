#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate

int main() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    long long ans = 0;
    for (int i = n * 2 - 2; i >= n; i -= 2) {
        ans += A[i];
    }

    std::cout << ans << std::endl;
    return 0;
}
