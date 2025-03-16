
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> cookies(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> cookies[i];
    }

    int leftOver = cookies[0] - cookies[2];
    int takahashi = std::max(0, leftOver);

    std::cout << takahashi <<'';
    if (takahashi > 0) {
        std::cout << cookies[1];
    } else {
        std::cout << std::max(0, cookies[1] - std::abs(leftOver));
    }

    return 0;
}

