#include <iostream>
#include <vector>
#include <algorithm>

#define N 1000000
#define Q 50000

int n;
std::vector<int> S; // Use vector for dynamic array
std::vector<int> T; // Use vector for queries

// Function to perform binary search on an array
bool binarySearch(int key) {
    int left = 0, right = n; // Initialize left and right pointers
    while (left < right) { // While the array is not yet searched completely
        int mid = (left + right) / 2; // Calculate the middle index
        if (S[mid] == key) return true; // If key is found, return true
        else if (key < S[mid]) right = mid; // If key is smaller, search in left half
        else left = mid + 1; // If key is greater, search in right half
    }
    return false; // If key is not present in the array, return false
}

int main() {
    int q, c = 0; // Initialize variables

    // Read the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    // Resize the vector to hold n elements
    S.resize(n);

    // Read the elements of the array
    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Element " << (i + 1) << ": ";
        std::cin >> S[i];
    }

    // Read the number of queries
    std::cout << "Enter the number of queries: ";
    std::cin >> q;

    // Resize the vector to hold q queries
    T.resize(q);

    // Read the queries
    std::cout << "Enter " << q << " integers to be searched:\n";
    for (int i = 0; i < q; i++) {
        std::cout << "Query " << (i + 1) << ": ";
        std::cin >> T[i];

        // Check if the query is present in the array
        if (binarySearch(T[i])) c++;
    }

    // Print the number of queries present in the array
    std::cout << "Number of queries present in the array: " << c << std::endl;

    return 0;
}

// <END-OF-CODE>
