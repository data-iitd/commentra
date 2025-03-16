
#include <iostream> // Include the necessary header file for input/output operations

int main() {
    // Create a variable to hold the final result
    long long ans = 0;
    
    // Read an integer input from the user
    int n;
    std::cin >> n;
    
    // Loop through each integer from 1 to n (inclusive)
    for (int i = 1; i <= n; i++) {
        // Calculate the contribution of the current integer i to the result
        // This involves multiplying i by the number of times i fits into n
        // and summing up the series of numbers from 1 to (n / i)
        ans += (long long) i * ((long long) n / (long long) i) * (((long long) n / (long long) i) + 1) / 2;
    }
    
    // Output the final result
    std::cout << ans << std::endl;
    
    return 0; // Return 0 to indicate successful program execution
}

