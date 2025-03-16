#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> ans(n);

    for (int i = 0; i < n; i++) {
        std::cin >> ans[i];
    }

    std::sort(ans.begin(), ans.end());

    long long count = ans[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (ans[i] < ans[i + 1]) {
            count += ans[i];
        } else {
            while (ans[i] >= ans[i + 1]) {
                ans[i]--;
            }
            if (ans[i] > 0) {
                count += ans[i];
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}
