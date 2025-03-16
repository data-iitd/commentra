#include <iostream> // Include the iostream library for input and output
using namespace std;

int maxLeft(int n) {
    // Return n - 2 if n is greater than 2, otherwise return 0
    return n > 2 ? n - 2 : 0;
}

int main() {
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
    
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
