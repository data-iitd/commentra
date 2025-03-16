#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    int sum = 0;

    // Read n integers from the user and store them in the array arr, while updating the sum
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }

    int c = 0; // Initialize count of valid elements to remove
    std::string result = ""; // Create a string to build the output string

    // Iterate through the array arr to find elements that can be removed
    for (int i = 0; i < n; i++) {
        // Check if removing the current element keeps the average unchanged
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++; // Increment the count
            result += std::to_string(i + 1) + " "; // Append the index (plus one) to the string
        }
    }

    // Print the count of valid elements and the indices of these elements
    std::cout << c << std::endl;
    std::cout << result << std::endl;

    return 0;
}
