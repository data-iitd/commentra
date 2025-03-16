
// Include necessary headers for file I/O and collections
#include <iostream>
#include <vector>
#include <cmath>

// Define the main function, which is the entry point of the program
int main() {

    // Create a std::cin object to read input from the standard input
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    // Read the first integer n representing the size of the array
    int n;
    std::cin >> n;

    // Create a std::vector<int> arr of size n to store the input array
    std::vector<int> arr(n);

    // Use a for loop to read n integers from the standard input and store them in the vector arr
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i]; // Read the next integer and store it in the current index of the vector
    }

    // Initialize a variable ans with the first element of the vector arr and add 1 to it
    int ans = arr[0] + 1;

    // Use another for loop to iterate through the remaining elements of the vector arr
    for (int i = 1; i < n; i++) {
        // Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
        ans += std::abs(arr[i] - arr[i - 1]) + 2;
    }

    // Finally, print the value of ans to the standard output
    std::cout << ans << std::endl;

    return 0;
}
