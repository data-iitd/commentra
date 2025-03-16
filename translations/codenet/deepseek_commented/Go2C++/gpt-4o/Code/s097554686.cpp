#include <iostream>
#include <vector>

const int size = 100001;

int main() {
    int n, t; // Declare variables for number of intervals and time range
    int l, r; // Declare variables for left and right endpoints of intervals
    std::vector<int> mem(size, 0); // Declare a vector to store cumulative changes

    std::cin >> n; // Read the number of intervals
    std::cin >> t; // Read the time range

    // Read each interval and update the cumulative changes in the vector
    for (int i = 0; i < n; i++) {
        std::cin >> l; // Read the left endpoint
        std::cin >> r; // Read the right endpoint
        mem[l] += 1; // Increment the value at the left endpoint
        mem[r] -= 1; // Decrement the value at the right endpoint
    }

    // Initialize ans with the value at mem[0]
    int ans = mem[0];

    // Compute the prefix sum and find the maximum value in the vector
    for (int i = 1; i <= t; i++) {
        mem[i] += mem[i - 1]; // Compute the prefix sum
        if (ans < mem[i]) { // Update ans if a larger value is found
            ans = mem[i];
        }
    }

    // Print the maximum value found
    std::cout << ans << std::endl;

    return 0;
}

// <END-OF-CODE>
