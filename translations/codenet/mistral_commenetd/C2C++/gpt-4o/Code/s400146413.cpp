#include <iostream>
#include <vector>

using namespace std;

// Function to perform linear search on an array
int linearsearch(const vector<int>& S, int n, int key) {
    int i = 0; // Initialize index variable i to 0

    // Search for the key in the array S until it is found or the end of the array is reached
    while (i < n && S[i] != key) {
        i++; // Increment i by 1 for each iteration
    }

    // If key is found, return 0 to indicate that it was found
    // If key is not found, return 1
    return (i < n) ? 0 : 1;
}

// Main function to read input and call linearsearch function
int main() {
    int n, q; // Declare and initialize variables
    int count = 0; // Initialize count variable to 0

    // Read the size of the array S from the user
    cout << "Enter the size of the array S: ";
    cin >> n;

    vector<int> S(n); // Declare vector S of size n

    // Read the elements of array S from the user
    cout << "Enter " << n << " integers for array S:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter integer S[" << i << "]: ";
        cin >> S[i];
    }

    // Read the number of queries from the user
    cout << "Enter the number of queries: ";
    cin >> q;

    vector<int> T(q); // Declare vector T of size q

    // Read the elements of array T from the user
    cout << "Enter " << q << " integers for array T:" << endl;
    for (int j = 0; j < q; j++) {
        cout << "Enter integer T[" << j << "]: ";
        cin >> T[j];
    }

    // Call linearsearch function for each element of array T and increment count if key is not found
    for (int j = 0; j < q; j++) {
        int key = T[j]; // Assign the current element of array T to key variable
        if (linearsearch(S, n, key) == 1) { // Call linearsearch function and check if count is 1 (key not found)
            count++; // Increment count if key is not found
        }
    }

    // Print the final count to the user
    cout << "Number of integers in array S that are not present in array T: " << count << endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
