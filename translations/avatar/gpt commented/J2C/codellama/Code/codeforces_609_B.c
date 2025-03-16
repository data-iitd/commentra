#include <stdio.h>

int main() {
    // Create a Scanner object to read input from the console
    int n, m, i, k;
    scanf("%d %d", &n, &m);
    
    // Read the number of elements (n) and the maximum value (m)
    int arr[n];
    
    // Initialize an array to store the input values
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Store the input value in arr
    }
    
    // Initialize a frequency array to count occurrences of each number from 1 to 10
    int gen[11]; // gen[0] will remain unused
    
    // Read n integers from input and populate the arr and gen arrays
    for (i = 0; i < n; i++) {
        gen[arr[i]]++; // Increment the count of the corresponding number in gen
    }
    
    // Initialize a variable to hold the final answer
    long ans = 0;
    
    // Calculate the number of valid pairs (i, k) where i != k
    for (i = 1; i <= m; i++) {
        for (k = 1; k <= m; k++) {
            if (i != k) {
                // Add the product of the counts of i and k to the answer
                ans += (long) gen[i] * gen[k];
            }
        }
    }
    
    // Since each pair (i, k) is counted twice, divide the result by 2
    printf("%ld\n", ans / 2);
    
    return 0;
}

