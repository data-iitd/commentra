#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Take input from the user
    int n;
    std::cin >> n;
    // Read the input, split it into a list of integers, and store it in 'a'
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    // Sort the vector 'a'
    std::sort(a.begin(), a.end());
    // Iterate through the sorted vector starting from the second element
    for (int i = 1; i < n; ++i) {
        // Check if the current element is not equal to the previous element
        // and if the current element is less than twice the previous element
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, print 'YES' and return 0
            std::cout << "YES" << std::endl;
            return 0;
        }
    }
    // If the loop completes without finding a match, print 'NO'
    std::cout << "NO" << std::endl;
    return 0;
}

