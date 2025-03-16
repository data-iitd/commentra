#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i];
    }

    std::sort(elements.begin(), elements.end());

    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += elements[i];
    }

    std::cout << sum << std::endl;

    return 0;
}
