
#include <iostream> // Include the iostream library for input/output operations

int main() {
    // Create a Scanner object to read input from the user
    std::cin.sync_with_stdio(false); // Disable buffering for input
    
    // Read two integers from the user: n and k
    int n, k;
    std::cin >> n >> k;
    
    // Increment n by 1
    n++;
    
    // Initialize a variable z to store the adjustment needed to make n divisible by k
    int z = 0;
    
    // Check if n is not divisible by k
    if (n % k!= 0) {
        // Calculate the adjustment needed to make n divisible by k
        z = k - n % k;
    }
    
    // Output the final result, which is n plus the adjustment z
    std::cout << n + z << std::endl; // Use std::endl to insert a new line after the output
    
    return 0; // Return 0 to indicate successful program execution
}
