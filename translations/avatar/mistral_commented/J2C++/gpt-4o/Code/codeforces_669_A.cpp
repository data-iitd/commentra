#include <iostream> // Include iostream for input and output
using namespace std; // Use the standard namespace

int main() {
    int n; // Declare an integer variable 'n' to store the input number

    // Read the input number from the console and store it in the 'n' variable
    cout << "Enter a number: ";
    cin >> n;

    // Call the 'solve' function to calculate and print the result
    cout << (n / 3) * 2 + (n % 3 == 0 ? 0 : 1) << endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
