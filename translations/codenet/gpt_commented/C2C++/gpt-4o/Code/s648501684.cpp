#include <iostream>
#include <vector>

int main() {
    // Declare variables to hold the number of elements (n), the threshold (k), and the number of queries (q)
    long int n, k, q;

    // Read the values of n, k, and q from user input
    std::cin >> n >> k >> q;

    // Initialize a vector to count occurrences of each element, with size n+1 (to use 1-based indexing)
    std::vector<int> arr(n + 1, 0); // Set all elements of the vector to 0

    // Process each query to count occurrences of the queried elements
    for (long int i = 0; i < q; i++) {
        long int temp;
        // Read the queried element and increment its count in the vector
        std::cin >> temp;
        arr[temp] += 1; // Increment the count for the queried element
    }

    // Check each element from 1 to n to see if its count exceeds the threshold (q - k)
    for (long int i = 1; i <= n; i++) {
        // If the count of the element is greater than (q - k), print "Yes"
        if (arr[i] > (q - k)) {
            std::cout << "Yes\n";
        } else {
            // Otherwise, print "No"
            std::cout << "No\n";
        }
    }

    return 0; // End of the program
} // <END-OF-CODE>
