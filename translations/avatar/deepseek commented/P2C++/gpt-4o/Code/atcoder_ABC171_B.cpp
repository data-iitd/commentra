#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    // This line takes two integers, n and k, as input from the user.
    std::cin >> n >> k;

    std::vector<int> numbers(n);
    // This line takes n integers as input from the user.
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // This line sorts the numbers and calculates the sum of the first k smallest numbers.
    std::sort(numbers.begin(), numbers.end());
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += numbers[i];
    }

    std::cout << sum << std::endl;

    return 0;
}
// <END-OF-CODE>
