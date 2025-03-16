#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int a;
    std::cin >> a;
    std::vector<int> ar(a);
    int max = 0, min = 0;

    for (int i = 0; i < ar.size(); i++) {
        std::cin >> ar[i];
    }

    for (int i = 0; i < ar.size(); i++) {
        max = std::max(ar[i] - ar[0], ar[ar.size() - 1] - ar[i]);
        if (i == 0) {
            min = ar[i + 1] - ar[i];
        } else if (i == ar.size() - 1) {
            min = ar[i] - ar[i - 1];
        } else {
            min = std::min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]);
        }
        std::cout << min << " " << max << std::endl;
    }

    return 0;
}
