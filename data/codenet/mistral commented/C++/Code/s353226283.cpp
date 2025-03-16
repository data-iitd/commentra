
#include <vector>
#include <iostream>
#include <algorithm>

// Define input variables
int n, k, t;
std::vector<int> vec;
int ans = 1000000001;

int main() {
    // Read input values for n and k
    std::cin >> n >> k;

    // Initialize vector 'vec' with size 'n'
    for (int i = 0; i < n; i++) {
        // Read input value for 't' and add it to the vector
        std::cin >> t;
        vec.push_back(t);
    }

    // Sort the vector 'vec' in ascending order
    std::sort(vec.begin(), vec.end());

    // Iterate through the vector with a sliding window of size 'k'
    for (int i = 0; i + k -1 < n; i++) {
        // Calculate the difference between the last and first element of the current window
        int diff = vec[i+k-1] - vec[i];

        // Update the answer if the current difference is smaller than the previous one
        if (diff < ans) {
            ans = diff;
        }
    }

    // Print the answer
    std::cout << ans << std::endl;

    return 0;
}