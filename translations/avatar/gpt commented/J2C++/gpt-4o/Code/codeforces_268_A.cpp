#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays

using namespace std;

int main() {
    // Reading the number of elements (n) from the user
    int n;
    cin >> n;

    // Initializing a variable to store the result of matching elements
    int result = 0;

    // Creating two vectors to hold the input values
    vector<int> h(n); // Vector to store the first set of integers
    vector<int> g(n); // Vector to store the second set of integers

    // Reading n integers into the first vector (h)
    for (int i = 0; i < n; i++) {
        cin >> h[i]; // Storing input in vector h
    }

    // Reading n integers into the second vector (g)
    for (int i = 0; i < n; i++) {
        cin >> g[i]; // Storing input in vector g
    }

    // Comparing each element of vector h with each element of vector g
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If a match is found, increment the result counter
            if (h[i] == g[j]) {
                result++; // Incrementing the count of matches
            }
        }
    }

    // Outputting the total number of matches found
    cout << result << endl;

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
