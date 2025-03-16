
#include <iostream> // Include the necessary libraries for input/output operations
#include <sstream> // Include the stringstream library for string manipulation
#include <string> // Include the string library for string operations

using namespace std; // Use the standard namespace for convenience

int main() {
    int n, x; // Declare and initialize the variables n and x
    cin >> n >> x; // Read the input values for n and x
    print(x, n); // Call the print function with x and n as arguments
    return 0; // Return 0 to indicate successful execution
}

// Function to print based on the value of x and n
void print(int x, int n) {
    int max = n * 2 - 1; // Calculate the maximum value based on n
    if (x == 1 || x == max) { // Check if x is at the edges
        cout << "No" << endl; // Print "No" if x is 1 or max
        return; // Exit the function
    }
    cout << "Yes" << endl; // Print "Yes" if x is within the valid range
    stringstream ans; // Create a stringstream object to store the constructed string
    for (int i = x + n - 1; i < x + n + max - 1; i++) { // Iterate over the required range
        ans << (i % max + 1) << endl; // Append each number to the stringstream
    }
    cout << ans.str(); // Print the constructed string
}

