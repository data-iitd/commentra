#include <iostream>
#include <initializer_list>
#include <algorithm>

int min(std::initializer_list<int> nums) {
    return *std::min_element(nums.begin(), nums.end());
}

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::cout << min({n * a, b}) << std::endl;

    return 0;
}

// <END-OF-CODE>
