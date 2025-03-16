#include <iostream>
#include <vector>

int main() {
    int y;
    std::cin >> y;

    std::vector<int> arr(y);
    for (int i = 0; i < y; ++i) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < y; ++j) {
            if (i == j) continue;
            for (int k = 0; k < y; ++k) {
                if (k == i || k == j) continue;
                if (arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j]) {
                    std::cout << k + 1 << " " << j + 1 << " " << i + 1 << std::endl;
                    return 0;
                }
            }
        }
    }

    std::cout << -1 << std::endl;
    return 0;
}

