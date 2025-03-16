#include <iostream>
#include <vector>

// Function to search for a key in the array A of size n
bool search(const std::vector<int>& A, int n, int key) {
    int i = 0; // Initialize index to 0
    std::vector<int> arr = A; // Create a copy of the array
    arr.push_back(key); // Sentinel value: place the key at the end of the array
    // Loop until the key is found in the array
    while (arr[i] != key) i++; // Increment index until the key is found
    // Return true if the key was found before the sentinel, false otherwise
    return i != n;
}

int main() {
    int n, q, key, sum = 0; // Declare variables

    // Read the number of elements in the array
    std::cin >> n;
    std::vector<int> A(n); // Declare a vector of size n

    // Read the elements of the array
    for (int i = 0; i < n; i++) std::cin >> A[i];
    
    // Read the number of queries
    std::cin >> q;
    // Process each query
    for (int i = 0; i < q; i++) {
        std::cin >> key; // Read the key to search for
        // If the key is found in the array, increment the sum
        if (search(A, n, key)) sum++;
    }
    
    // Output the total count of found keys
    std::cout << sum << std::endl;

    return 0; // End of the program
}

// <END-OF-CODE>
