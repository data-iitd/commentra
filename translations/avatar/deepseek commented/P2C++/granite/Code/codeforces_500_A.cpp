

#include <iostream>
#include <vector>

int main() {
    int n, t;
    std::cin >> n >> t;

    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    int current_cell = 0;
    while (current_cell <= t) {
        current_cell += s[current_cell - 1];
        if (current_cell == t) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;

    return 0;
}
