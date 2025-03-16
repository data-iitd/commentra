#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());

    bool found = false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (i + 1 < a.size() && i + 2 < a.size()) {
            if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
                found = true;
                break;
            }
        }
    }

    std::cout << (found ? "YES" : "NO") << std::endl;
    return 0;
}

