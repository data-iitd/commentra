#include <iostream>
#include <vector>

// Function to perform linear search on an array
int linearsearch(const std::vector<int>& S, int key) {
    int i = 0; // Initialize index for searching
    int count = 0; // Initialize count to track if the key is found

    // Loop until the key is found or the end of the array is reached
    while (i < S.size() && S[i] != key) {
        i++; // Move to the next index
    }
    
    // If the index exceeds the size of the array, the key is not found
    if (i >= S.size()) {
        count = 1; // Set count to indicate the key was not found
    }
    
    return count; // Return count (0 if key is found)
}

int main() {
    int n, q; // Declare variables for sizes
    std::vector<int> S; // Vector for the first array
    std::vector<int> T; // Vector for the second array (the keys to search)
    int count = 0; // Initialize count for missing keys

    // Read the number of elements in the first array
    std::cin >> n;
    S.resize(n); // Resize the vector to hold n elements
    // Read the elements into the first array S
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }

    // Read the number of queries
    std::cin >> q;
    T.resize(q); // Resize the vector to hold q elements
    // Read the elements into the second array T
    for (int j = 0; j < q; j++) {
        std::cin >> T[j];
    }

    // Loop through each key in T to check if it exists in S
    for (int j = 0; j < q; j++) {
        int key = T[j]; // Get the current key to search
        // If the key is not found in S, increment the count
        if (linearsearch(S, key) == 0) {
            count++; // Increment count for each missing key
        }
    }

    // Print the total count of keys that were not found in S
    std::cout << count << std::endl;

    return 0; // Exit the program
}

// <END-OF-CODE>
