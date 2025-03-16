#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    try {
        std::set<int> a;
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int value;
            std::cin >> value;
            a.insert(value);
        }

        std::vector<int> sorted_a(a.begin(), a.end());
        bool found = false;
        for (size_t i = 0; i < sorted_a.size(); i++) {
            if (i + 1 < sorted_a.size() && i + 2 < sorted_a.size()) {
                if (sorted_a[i] + 1 == sorted_a[i + 1] && sorted_a[i + 1] + 1 == sorted_a[i + 2]) {
                    found = true;
                    break;
                }
            }
        }

        std::cout << (found ? "YES" : "NO") << std::endl;

    } catch (...) {
        std::cerr << "An error occurred." << std::endl;
    }

    return 0;
}

