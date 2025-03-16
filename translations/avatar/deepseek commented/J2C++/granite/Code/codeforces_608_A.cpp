
#include <bits/stdc++.h> // Including the necessary libraries

using namespace std; // Using the standard namespace

int main() { // Defining the main function
    ios_base::sync_with_stdio(false); // Disabling synchronization between C and C++ streams
    cin.tie(NULL); // Setting the input stream to null

    int n, s, max = 0; // Declaring and initializing variables n, s, and max

    cin >> n >> s; // Reading the values of n and s from the input

    while (n-- > 0) { // Looping n times
        int f, t; // Declaring variables f and t

        cin >> f >> t; // Reading the values of f and t from the input

        if (max < f + t) { // Checking if the sum of f and t is greater than max
            max = f + t; // Updating max if the condition is true
        }
    }

    cout << max(max, s) << endl; // Printing the maximum of max and s

    return 0; // Returning 0 to indicate successful execution
}

