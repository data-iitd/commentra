#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i + 1] < a[i] * 2 && a[i] != a[i + 1]) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }
    std::cout << "NO" << std::endl;
    return 0;
}

