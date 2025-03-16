#include <iostream>
#include <vector>
#include <cstdlib> // for std::exit

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    if (arr[0] > 15) {
        std::cout << 15 << std::endl;
        return 0;
    }

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] - arr[i - 1] > 15) {
            std::cout << arr[i - 1] + 15 << std::endl;
            return 0;
        }
    }

    if (arr.back() == 90 || arr.back() + 15 >= 90) {
        std::cout << 90 << std::endl;
    } else {
        std::cout << arr.back() + 15 << std::endl;
    }

    return 0;
}
