
#include <iostream> // Include the necessary header file for input/output operations

using namespace std; // Using the standard namespace for input/output operations

int main() {
    int n, k; // Declare two integer variables n and k
    string a; // Declare a string variable a
    
    // Read two integers n and k from user input
    cin >> n >> k;
    
    // Read a string a from user input
    cin >> a;
    
    // Check if k is greater than half of n
    if (k > n / 2) {
        // If true, move to the right until k equals n
        while (k < n) {
            cout << "RIGHT" << endl; // Output "RIGHT" for each step to the right
            k++; // Increment k
        }
    } else {
        // If false, move to the left until k equals 1
        while (k > 1) {
            cout << "LEFT" << endl; // Output "LEFT" for each step to the left
            k--; // Decrement k
        }
    }
    
    // If k equals 1, print the characters of the string from left to right
    if (k == 1) {
        for (int i = 0; i < a.length(); i++) {
            cout << "PRINT " << a[i] << endl; // Print the current character
            // If not at the last character, output "RIGHT"
            if ((i + 1) < a.length()) {
                cout << "RIGHT" << endl;
            }
        }
    } else {
        // If k is not 1, print the characters of the string from right to left
        for (int i = a.length() - 1; i >= 0; i--) {
            cout << "PRINT " << a[i] << endl; // Print the current character
            // If not at the first character, output "LEFT"
            if ((i - 1) >= 0) {
                cout << "LEFT" << endl;
            }
        }
    }
    
    return 0; // Return 0 to indicate successful execution of the program
}

