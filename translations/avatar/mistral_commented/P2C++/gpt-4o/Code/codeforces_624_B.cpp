#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    // Read an integer n from the standard input
    int n;
    std::cin >> n;

    // Create a vector a of size n by reading n integers from the standard input
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Initialize two variables, pre and ans, to infinity and 0, respectively
    int pre = std::numeric_limits<int>::max();
    long long ans = 0;

    // Sort the vector a in descending order
    std::sort(a.rbegin(), a.rend());

    // Iterate through the vector a using a for loop
    for (int j = 0; j < n; ++j) {
        // Calculate the maximum of 0 and the minimum of pre - 1 and a[j]. This value is added to ans.
        ans += std::max(0, std::min(pre - 1, a[j]));

        // Update the value of pre to be the minimum of pre - 1 and a[j].
        pre = std::min(pre - 1, a[j]);
    }

    // After the loop, print the value of ans.
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
