#include <iostream> // Include the iostream library for input and output
#include <sstream>  // Include the sstream library for string stream operations

using namespace std;

void print(int x, int n) {
    int max = n * 2 - 1; // Calculate the maximum value based on n
    if (x == 1 || x == max) { // Check if x is at the edges
        cout << "No" << endl; // Print "No" if x is 1 or max
        return; // Exit the function
    }
    cout << "Yes" << endl; // Print "Yes" if x is within the valid range
    stringstream ans; // Create a string stream to build the output
    for (int i = x + n - 1; i < x + n + max - 1; ++i) { // Generate the required range
        ans << (i % max + 1) << endl; // Append each number to the string stream
    }
    cout << ans.str(); // Print the constructed string
}

int main() {
    int n, x; // Declare variables for input
    cin >> n >> x; // Read the first and second integer input
    print(x, n); // Call the print function with x and n as arguments
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
