#include <iostream> // Importing the iostream library for input and output operations
#include <vector>   // Importing the vector library for using dynamic arrays
using namespace std; // Using the standard namespace

// Function to read an integer from input
int nextInt() {
    int i;
    cin >> i; // Reading an integer from standard input
    return i; // Returning the integer
}

int main() {
    // Reading three integers and checking if their sum is greater than or equal to the third integer
    if (nextInt() + nextInt() >= nextInt()) {
        cout << "Yes" << endl; // Printing "Yes" if the condition is true
    } else {
        cout << "No" << endl; // Printing "No" if the condition is false
    }
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
