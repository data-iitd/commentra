#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    int max = -1;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
        if (max < h[i]) max = h[i];

        if (max - h[i] >= 2) flag = true;
    }

    if (flag) std::cout << "No\n";
    else std::cout << "Yes\n";

    return 0;
}

// <END-OF-CODE>
