#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using dynamic arrays
using namespace std; // Using the standard namespace

int main() { // Defining the main function
    int n; // Declaring an integer variable n
    cin >> n; // Reading the first line of input containing the number of integers n

    int result = 0; // Initializing the variable result to zero

    vector<int> h(n); // Creating a vector h of size n
    vector<int> g(n); // Creating a vector g of size n

    for (int i = 0; i < n; i++) { // Iterating through each index i from 0 to n-1
        cin >> h[i]; // Reading an integer value from the standard input stream and assigning it to the current index of vector h
        cin >> g[i]; // Reading an integer value from the standard input stream and assigning it to the current index of vector g
    }

    for (int i = 0; i < n; i++) { // Iterating through each index i from 0 to n-1
        for (int j = 0; j < n; j++) { // Nested for loop iterating through each index j from 0 to n-1
            if (h[i] == g[j]) { // Checking if the current element of vector h is equal to the current element of vector g
                result++; // Incrementing the result variable if the condition is true
            }
        }
    }

    cout << result << endl; // Printing the final result to the standard output stream
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
