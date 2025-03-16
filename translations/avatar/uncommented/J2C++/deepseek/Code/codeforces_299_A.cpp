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
    int min = a[0];
    for (int value : a) {
        if (value % min != 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::cout << min << std::endl;
    return 0;
}

