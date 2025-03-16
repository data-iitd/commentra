#include <iostream>

int main() {
    // Declare variables for the number of elements (n), the threshold (k), and a counter (cnt)
    int n, k, cnt;

    // Read the number of elements and the threshold value from user input
    std::cin >> n >> k;
    
    // Initialize the counter to zero
    cnt = 0;

    // Loop through each element, decrementing n until it reaches zero
    while (n--) {
        int h;

        // Read the current element from user input
        std::cin >> h;
        
        // Check if the current element is greater than or equal to the threshold
        if (h >= k)
            // Increment the counter if the condition is met
            cnt++;
    }

    // Output the final count of elements that met or exceeded the threshold
    std::cout << cnt << std::endl;
    
    // Return 0 to indicate successful execution of the program
    return 0;
}
