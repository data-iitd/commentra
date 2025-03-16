#include <iostream>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    Scanner scan;
    
    // Read the number of test cases
    int t;
    cin >> t;
    
    // Loop through each test case
    for (int i = 0; i < t; i++) {
        // Read the integer n for the current test case
        int n;
        cin >> n;
        
        // Call the maxLeft function and print the result
        cout << maxLeft(n) << endl;
    }
    
    // Close the scanner to prevent resource leaks
    scan.close();
    return 0;
}

// Function to calculate the maximum value based on the input n
int maxLeft(int n) {
    // Return n - 2 if n is greater than 2, otherwise return 0
    return n > 2 ? n - 2 : 0;
}

