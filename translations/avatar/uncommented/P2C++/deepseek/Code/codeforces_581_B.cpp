#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::vector<int> ans(n, 0);
    int mx = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        ans[i] = std::max(0, mx - arr[i] + 1);
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

