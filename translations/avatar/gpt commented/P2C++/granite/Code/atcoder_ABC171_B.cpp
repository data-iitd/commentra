
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }

    std::cout << sum << std::endl;

    return 0;
}
