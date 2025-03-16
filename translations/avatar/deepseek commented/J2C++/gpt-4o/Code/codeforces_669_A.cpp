#include <iostream> // Including iostream for input and output
using namespace std; // Using the standard namespace

int main() {
    int n; // Declaring an integer variable n
    cin >> n; // Reading an integer input from the user and storing it in variable n
    // Calculating the result based on the given logic
    cout << (n / 3) * 2 + (n % 3 == 0 ? 0 : 1) << endl; // Printing the result to the console
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
