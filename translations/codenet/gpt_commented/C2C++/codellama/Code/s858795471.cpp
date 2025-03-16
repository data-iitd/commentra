#include <iostream>

// Function to search for a key in the array A of size n
bool search(int A[], int n, int key) {
    int i = 0; // Initialize index to 0
    A[n] = key; // Sentinel value: place the key at the end of the array
    // Loop until the key is found in the array
    while (A[i] != key) i++; // Increment index until the key is found
    // Return true if the key was found before the sentinel, false otherwise
    return i != n;
}

int main() {
    int n, A[10000 + 1], q, key, sum = 0; // Declare variables
    int i;

    // Read the number of elements in the array
    std::cin >> n;
    // Read the elements of the array
    for (i = 0; i < n; i++) std::cin >> A[i];
    
    // Read the number of queries
    std::cin >> q;
    // Process each query
    for (i = 0; i < q; i++) {
        std::cin >> key; // Read the key to search for
        // If the key is found in the array, increment the sum
        if (search(A, n, key)) sum++;
    }
    
    // Output the total count of found keys
    std::cout << sum << std::endl;

    return 0; // End of the program
}

