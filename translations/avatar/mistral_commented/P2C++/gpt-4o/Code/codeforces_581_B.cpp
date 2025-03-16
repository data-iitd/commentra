#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Take the number of elements in the array as input
    int n;
    std::cin >> n;

    // Initialize a vector 'arr' of size 'n' and fill it with integers taken as input
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Initialize a vector 'ans' of size 'n' with zeros
    std::vector<int> ans(n, 0);

    // Variable 'mx' stores the maximum element in the array
    int mx = arr[n - 1];

    // Iterate through the array from index 'n-2' to '0' in reverse order
    for (int i = n - 2; i >= 0; --i) {
        // Update the answer at current index 'i' based on the maximum element 'mx' and current element 'arr[i]'
        ans[i] = std::max(0, mx - arr[i] + 1);

        // If the current element 'arr[i]' is greater than the maximum element 'mx', update 'mx'
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    // Print the answer list
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
