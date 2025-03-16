#include <iostream> // Include the standard input/output library
using namespace std; // Use the standard namespace

int main() // Start of the main function
{
    int a, b; // Declare two integer variables 'a' and 'b'
    cin >> a >> b; // Read two integers from the standard input and store them in variables 'a' and 'b'

    // First if block: If 'a' is equal to 1, assign 14 to 'a'
    if (a == 1)
        a = 14;

    // Second if block: If 'b' is equal to 1, assign 14 to 'b'
    if (b == 1)
        b = 14;

    // Determine who wins based on the values of 'a' and 'b'
    if (a < b)
        cout << "Bob" << endl; // If 'a' is less than 'b', print "Bob"
    else if (a > b)
        cout << "Alice" << endl; // If 'a' is greater than 'b', print "Alice"
    else
        cout << "Draw" << endl; // If 'a' is equal to 'b', print "Draw"

    return 0; // Indicate successful termination of the program
}

// <END-OF-CODE>
