
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;  // Read the number of elements in the list
    std::vector<int> l(n);  // Initialize a vector of size n to store the elements

    // Read n elements and store them in the vector l
    for (int i = 0; i < n; i++) {
        std::cin >> l[i];
    }

    int ans = n - 1;  // Initialize ans to n - 1, which will store the final answer
    int last = 0;  // Initialize last to 0, used to track the last element in the list

    // Iterate over each element in the vector l
    for (int i = 0; i < n; i++) {
        ans += abs(last - l[i]) + 1;  // Update ans based on the current element and last element
        last = l[i];  // Update last to the current element
    }

    std::cout << ans << std::endl;  // Print the final answer

    return 0;
}
