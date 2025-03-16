#include <iostream>
using namespace std;

// Function to search for a key in an array
bool search(int A[], int n, int key) {
    int i = 0;
    // Add the key to the end of the array
    A[n] = key;
    // Search for the key in the array using a while loop
    while (A[i] != key) i++;
    // Return true if the key was found before the end of the array, otherwise return false
    return i != n;
}

int main() {
    int n, // Number of elements in the array
        A[10000 + 1], // Array to store the elements
        q, // Number of queries
        key, // Key to be searched for
        sum = 0, // Variable to store the number of keys found
        i; // Loop counter

    // Read the number of elements in the array from the user
    cin >> n;
    // Read the elements of the array from the user
    for (i = 0; i < n; i++) cin >> A[i];
    // Read the number of queries from the user
    cin >> q;
    // For each query, search for the key in the array and if it is found, increment the sum
    for (i = 0; i < q; i++) {
        cin >> key; // Read the key to be searched for
        // Call the search function to find the key in the array
        if (search(A, n, key)) sum++; // If the key is found, increment the sum
    }
    // Print the number of keys found
    cout << sum << endl;

    return 0;
}

// <END-OF-CODE>
