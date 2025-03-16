#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::set<int> unique_a(a.begin(), a.end());
    std::vector<int> sorted_a(unique_a.begin(), unique_a.end());
    std::sort(sorted_a.begin(), sorted_a.end());

    bool found = false;
    for (size_t i = 0; i < sorted_a.size(); ++i) {
        if (i + 1 < sorted_a.size() && i + 2 < sorted_a.size()) {
            if (sorted_a[i] + 1 == sorted_a[i + 1] && sorted_a[i + 1] + 1 == sorted_a[i + 2]) {
                found = true;
                break;
            }
        }
    }

    std::cout << (found ? "YES" : "NO") << "\n";

    return 0;
}

