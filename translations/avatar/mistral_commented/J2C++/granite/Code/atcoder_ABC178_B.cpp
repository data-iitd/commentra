

#include <bits/stdc++.h> // Including necessary C++ standard library headers

using namespace std; // Using the standard namespace

int main() { // Main function for executing the program
    ios_base::sync_with_stdio(false); // Disabling synchronization between C and C++ standard input and output streams
    cin.tie(NULL); // Disabling buffering for C++ standard input

    long long a[4]; // Declaring and initializing an array of long long integers named a with size 4

    for (int i = 0; i < 4; i++) { // Iterating through the elements of the array a
        cin >> a[i]; // Reading the next long long integer from the input and storing it in the current element of the array
    }

    long long result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))); // Calculating the maximum product of pairs of elements in the array a

    cout << result << endl; // Printing the result to the standard output

    return 0; // Returning 0 to indicate successful program execution
}

These comments should provide a clear understanding of the code for anyone who reads it.

