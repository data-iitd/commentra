#include <iostream> // Include the iostream library for input and output
using namespace std; // Use the standard namespace

int main() 
{ 
    int a, b, x, w; // Declare variables to store input values and results
    while (cin >> a >> b) // Read two integers from standard input until end of file
    { 
        x = a + b; // Calculate the sum of the two integers
        w = 0; // Initialize the digit count to 0
        while (x) // Loop to count the number of digits in the sum
        { 
            w++; // Increment the digit count
            x /= 10; // Divide the sum by 10 to remove the last digit
        } 
        cout << w << endl; // Print the number of digits in the sum
    } 
    return 0; // Return 0 to indicate successful execution
} 

// <END-OF-CODE>
