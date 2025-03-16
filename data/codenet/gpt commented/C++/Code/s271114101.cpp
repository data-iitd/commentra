#include<iostream> // Include the iostream library for input and output operations

using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int main() {
    int a, b, c; // Declare three integer variables to hold the input values

    // Read three integers from the user
    cin >> a >> b >> c;

    // Check if any two of the three numbers sum up to the third number
    // If a + b equals c, or b + c equals a, or a + c equals b, print "Yes"
    // Otherwise, print "No"
    cout << ((a + b == c || b + c == a || a + c == b) ? "Yes" : "No") << endl;

    return 0; // Return 0 to indicate successful completion of the program
}
