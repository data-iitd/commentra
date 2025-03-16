#include <iostream> // Include the iostream library for input and output
using namespace std; // Use the standard namespace

// Function to perform a specific subtraction-like operation
int sub(int a, int b) {
    // Determine the minimum and maximum of the two numbers
    int min = std::min(a, b);
    int max = std::max(a, b);
    
    // Initialize the result variable to store the final output
    int result = 0;
    
    // Continue the process while min is greater than 0
    while (min > 0) {
        // Add the quotient of max divided by min to the result
        result += max / min;
        
        // Update max to be the remainder of max divided by min
        max = max % min;
        
        // Update min and max for the next iteration
        int curr_min = std::min(min, max);
        int curr_max = std::max(min, max);
        min = curr_min;
        max = curr_max;
    }
    
    // Return the final result
    return result;
}

int main() {
    // Create a variable to store the number of test cases
    int n;
    
    // Read the number of test cases from user input
    cin >> n;
    
    // Loop through each test case
    for (int i = 0; i < n; i++) {
        // Read two integers a and b from user input
        int a, b;
        cin >> a >> b;
        
        // Call the sub method and print the result
        cout << sub(a, b) << endl;
    }
    
    return 0; // Indicate that the program ended successfully
}

// <END-OF-CODE>
