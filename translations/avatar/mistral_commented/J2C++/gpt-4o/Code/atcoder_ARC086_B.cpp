#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using vectors
#include <cmath>    // Including the cmath library for mathematical functions
#include <algorithm> // Including the algorithm library for using algorithms like abs

using namespace std; // Using the standard namespace

int main() { // Starting point of the program
    int n; // Variable to store the number of elements
    cin >> n; // Reading the first integer from the standard input stream
    vector<int> a(n); // Creating a vector of integers of size n

    for (int i = 0; i < n; ++i) { // Loop to read n integers into the vector
        cin >> a[i]; // Reading integers into the vector
    }

    vector<string> r; // Creating an empty vector of strings to store the output
    int m = 0; // Initializing the variable m to 0

    for (int i = 1; i < n; ++i) { // Starting a for loop to iterate through the vector a from the second element to the last one
        if (abs(a[m]) < abs(a[i])) { // Comparing the absolute values of the first and current elements
            m = i; // Assigning the index of the smallest absolute value to the variable m
        }
    }

    for (int i = 0; i < n; ++i) { // Starting a for loop to iterate through the vector a from the first element to the last one
        if ((a[m] >= 0) ^ (a[i] >= 0)) { // Checking if the signs of the elements at indices m and i are different
            r.push_back(to_string(m + 1) + " " + to_string(i + 1)); // Adding the pair (m+1, i+1) to the vector r if the condition is true
        }
    }

    if (a[m] >= 0) { // Checking if the smallest absolute value is positive
        for (int i = 1; i < n; ++i) { // Starting a for loop to iterate through the vector a from the second element to the last one
            r.push_back(to_string(i) + " " + to_string(i + 1)); // Adding the pair (i, i+1) to the vector r if the smallest absolute value is positive
        }
    } else { // If the smallest absolute value is negative
        for (int i = n; i > 1; --i) { // Starting a for loop to iterate through the vector a from the last element to the second one
            r.push_back(to_string(i) + " " + to_string(i - 1)); // Adding the pair (i, i-1) to the vector r if the smallest absolute value is negative
        }
    }

    cout << r.size() << endl; // Printing the size of the vector r to the standard output stream
    for (const auto& str : r) { // Printing each pair in the vector r to the standard output stream
        cout << str << endl; // Outputting each string in the vector
    }

    return 0; // Returning 0 to indicate successful completion
} // End of main function
// <END-OF-CODE>
