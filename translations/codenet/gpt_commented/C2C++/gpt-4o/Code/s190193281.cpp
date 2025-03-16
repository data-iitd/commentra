#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort
#define N 1000000  // Maximum size for the array S
#define Q 50000    // Maximum size for the array T

int n;  // Declare variable for the number of elements
std::vector<int> S(N);  // Declare a vector for the sorted array
std::vector<int> T(Q);  // Declare a vector for the query array

// Function to perform binary search on the sorted array S
bool binarySearch(int key) {
    int left = 0, right = n;  // Initialize left and right pointers for the search range
    while (left < right) {  // Continue searching while the range is valid
        int mid = (left + right) / 2;  // Calculate the middle index
        if (S[mid] == key) return true;  // If the key is found, return true
        else if (key < S[mid]) right = mid;  // Narrow the search to the left half
        else left = mid + 1;  // Narrow the search to the right half
    }
    return false;  // If the key is not found, return false
}

int main() {
    int q, c = 0;  // Declare variables: q for number of queries, c for count of found keys
    
    // Read the number of elements in the sorted array S
    std::cin >> n;
    
    // Read the elements into the sorted array S
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }
    
    // Sort the array S
    std::sort(S.begin(), S.begin() + n);
    
    // Read the number of queries
    std::cin >> q;
    
    // Process each query to check if it exists in the sorted array S
    for (int i = 0; i < q; i++) {
        std::cin >> T[i];  // Read the query element into array T
        if (binarySearch(T[i])) c++;  // If the element is found, increment the count
    }
    
    // Output the total count of found elements
    std::cout << c << std::endl;
    
    return 0;  // Return 0 to indicate successful completion
}

// <END-OF-CODE>
