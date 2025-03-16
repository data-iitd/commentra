
#include <iostream> // Including the necessary header file for input/output operations
#include <vector> // Including the necessary header file for vector operations

using namespace std; // Using the standard namespace for input/output operations

int main() {
    int n; // Declaring a variable to store the number of elements (n)
    cin >> n; // Reading the number of elements (n) from the user

    vector<int> h(n); // Creating a vector to store the first set of integers
    vector<int> g(n); // Creating a vector to store the second set of integers

    for (int i = 0; i < n; i++) {
        cin >> h[i]; // Reading n integers into the first vector (h)
    }

    for (int i = 0; i < n; i++) {
        cin >> g[i]; // Reading n integers into the second vector (g)
    }

    int result = 0; // Initializing a variable to store the result of matching elements

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If a match is found, increment the result counter
            if (h[i] == g[j]) {
                result++; // Incrementing the count of matches
            }
        }
    }

    // Outputting the total number of matches found
    cout << result << endl; // Outputting the result

    return 0; // Returning 0 to indicate successful execution of the program
}
