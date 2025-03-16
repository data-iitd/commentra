
#include <iostream> // Include the necessary libraries
#include <sstream> // Include the necessary libraries
#include <string> // Include the necessary libraries
#include <vector> // Include the necessary libraries

using namespace std; // Use the standard namespace

void print(int x, int n) {
    int max = n * 2 - 1; // Calculate the maximum value based on n
    
    if (x == 1 || x == max) { // Check if x is equal to 1 or max
        cout << "No" << endl; // Print "No" and exit the method
        return; // Exit the method early
    }
    
    cout << "Yes" << endl; // If x is valid, print "Yes"
    
    string sep = "\n"; // Prepare the line separator for formatting output
    
    stringstream ss; // Create a stringstream object to collect the results
    
    for (int i = x + n - 1; i < x + n + max - 1; i++) { // Generate a sequence of numbers based on the input x and n
        int num = (i % max + 1); // Adjust the number to fit within the range
        ss << num << sep; // Append the number to the stringstream object
    }
    
    string ans = ss.str(); // Collect the results into a single string
    
    cout << ans; // Print the generated sequence
}

int main() {
    int n, x; // Declare variables for n and x
    
    cin >> n >> x; // Read two integers from user input: n and x
    
    print(x, n); // Call the print method with the inputs x and n
    
    return 0; // Return 0 to indicate successful execution
}

