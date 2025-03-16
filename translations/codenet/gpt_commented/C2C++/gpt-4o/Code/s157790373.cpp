#include <iostream>
#include <vector>
#define LEN 300
#define TRUE 1
#define FALSE -1

// Function prototype for the recursive solve function
int solve(int, int);
int n; // Number of elements
std::vector<int> A(LEN); // Array of elements
int flag; // Flag to indicate if a solution is found

int main() {
    int q, M; // q for the number of queries, M for the target sum

    // Read the number of elements in the array
    std::cin >> n;
    // Read the elements into the array A
    for(int i = 0; i < n; i++) std::cin >> A[i];

    // Read the number of queries
    std::cin >> q;
    // Process each query
    for(int i = 0; i < q; i++) {
        // Read the target sum for the current query
        std::cin >> M;
        flag = FALSE; // Reset flag for each query

        // Call the solve function to check if a subset sums to M
        solve(-1, M);
        // Output the result based on the flag
        if(flag == TRUE) std::cout << "yes\n";
        else std::cout << "no\n";
    }

    return 0; // End of the main function
}

// Recursive function to determine if a subset of A can sum to m
int solve(int i, int m) {
    // Base case: if index exceeds the number of elements
    if(i >= n) return FALSE;
    // Base case: if the remaining sum is negative
    else if(m < 0) return FALSE;
    // Base case: if the remaining sum is zero (solution found)
    else if(m == 0 || (i + 1 < n && m - A[i + 1] == 0)) {
        flag = TRUE; // Set flag to TRUE indicating a solution is found
        return TRUE; // Return TRUE
    } else {
        // Recursive case: do not use the current element A[i]
        solve(i + 1, m);
        // Recursive case: use the current element A[i]
        solve(i + 1, m - A[i]);
    }
}

