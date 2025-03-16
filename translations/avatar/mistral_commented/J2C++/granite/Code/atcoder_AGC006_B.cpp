

#include <iostream> // Including the necessary header files for input/output operations
#include <string> // Including the necessary header file for string operations
#include <sstream> // Including the necessary header file for string stream operations
#include <vector> // Including the necessary header file for vector operations

using namespace std; // Using the standard namespace for the code

int main() { // Main function to start the execution of the program
    int n, x; // Declaring two integer variables n and x to store the input values
    cin >> n >> x; // Reading the input values from the console using cin

    if (x == 1 || x == 2 * n - 1) { // Checking if x is the first or last index in the sequence
        cout << "No" << endl; // If true, print "No" and return
        return 0;
    }

    cout << "Yes" << endl; // If false, print "Yes"
    string ans = ""; // Declaring a string variable ans to store the final answer
    for (int i = x + n - 1; i <= x + n + 2 * n - 2; i++) { // Generating a sequence of integers from x+n-1 to x+n+2*n-2
        ans += to_string((i % (2 * n - 1) + 1)) + "\n"; // Appending a new line and the next integer to the ans string
    }

    cout << ans; // Printing the final answer
    return 0; // Returning 0 to indicate successful execution of the program
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!