#include <iostream>
#include <vector>
#include <cmath> // for std::abs

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int ans = arr[0] + 1;

    for (int i = 1; i < n; ++i) {
        ans += std::abs(arr[i] - arr[i - 1]) + 2;
    }

    std::cout << ans << std::endl;

    return 0;
}
