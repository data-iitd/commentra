

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;  // Read the number of elements in the list `r`
    std::cin >> n;

    std::vector<int> r(n);  // Read the space-separated string of integers and convert them to a vector of integers
    for (int i = 0; i < n; i++) {
        std::cin >> r[i];
    }

    int ans = std::abs(r[0]);  // Initialize `ans` to the absolute value of the first element in the vector `r`

    // The for loop iterates over the range from 1 to `n` (inclusive)
    // For each iteration, it adds the absolute difference between the current element and the previous element in the vector `r` to `ans`
    for (int i = 1; i < n; i++) {
        ans += std::abs(r[i] - r[i - 1]);
    }

    std::cout << ans << std::endl;  // Print the value of `ans`

    return 0;
}

