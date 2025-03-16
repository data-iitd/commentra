#include <stdio.h> // Including standard input-output library
#include <limits.h> // Including limits for integer values

int main() { // Starting the main function
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Reading the number of elements in the array from the console
    int maxn = 4010; // Defining the maximum size of the dynamic programming array

    // Reading the three integers representing the array elements
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // Defining an array to store the array elements
    int arr[3] = { a, b, c };

    int dp[maxn]; // Creating a dynamic programming array of size maxn

    // Initializing the dynamic programming array with minimum values
    for (int i = 0; i < n; i++) {
        dp[i] = INT_MIN; // Setting all elements to minimum value
    }

    dp[0] = 0; // Setting the first element to 0

    // Filling the dynamic programming array using two nested loops
    for (int i = 0; i < 3; i++) { // Looping through the array elements
        for (int j = arr[i]; j < maxn; j++) { // Looping through the dynamic programming array
            dp[j] = (dp[j] > dp[j - arr[i]] + 1) ? dp[j] : (dp[j - arr[i]] + 1); // Updating the maximum length ending at j
        }
    }

    // Printing the result, which is the maximum length ending at the nth index
    printf("%d\n", dp[n]); 

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
