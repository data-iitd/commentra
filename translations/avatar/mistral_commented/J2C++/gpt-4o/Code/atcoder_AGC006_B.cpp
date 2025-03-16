#include <iostream> // Including the iostream library for input and output
#include <vector> // Including the vector library for dynamic arrays

using namespace std; // Using the standard namespace

void print(int x, int n) { // Function to print the answer based on the given input
    int max = n * 2 - 1; // Calculating the maximum index for the sequence

    if (x == 1 || x == max) { // Checking if x is the first or last index in the sequence
        cout << "No" << endl; // If true, print "No" and return
        return;
    }

    cout << "Yes" << endl; // If false, print "Yes"
    for (int i = x + n - 1; i < x + n + max - 1; ++i) { // Generating a sequence of integers
        cout << (i % max + 1) << endl; // Printing each element of the sequence
    }
}

int main() { // Main function to start the execution of the program
    int n, x; // Declaring variables for input
    cin >> n; // Reading the first integer input from the user
    cin >> x; // Reading the second integer input from the user
    print(x, n); // Calling the print function with x and n as arguments
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
