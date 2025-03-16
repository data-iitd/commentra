

#include <iostream>  // Importing the standard input/output stream objects
#include <vector>  // Importing the vector container class
#include <algorithm>  // Importing the algorithm library for sorting and searching

using namespace std;

int main() {
    int n;  // Declaring an integer variable to store the first number

    // Reading the first number from the user input
    cin >> n;

    cout << n << " ";  // Printing the first number to the standard output stream

    int m = n;  // Initializing an integer variable'm' with the value of 'n'

    // Finding the factors of the number 'n' using a for loop
    for (int i = n - 1; i > 0; i--) {
        if (m % i == 0) {  // Checking if 'i' is a factor of'm'
            cout << i << " ";  // Printing the factor to the standard output stream
            m = i;  // Updating the value of'm' with the current factor
        }
    }

    return 0;
}

These comments should provide a clear understanding of the code's functionality and logic. Let me know if you need any further assistance.