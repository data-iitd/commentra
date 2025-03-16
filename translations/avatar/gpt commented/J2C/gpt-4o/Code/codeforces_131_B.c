#include <stdio.h> // Include standard input-output library

int main() {
    // Read the number of integers to process
    int n;
    scanf("%d", &n);
    
    // Initialize an array to count occurrences of integers in the range [-10, 10]
    long cnt[21] = {0}; // Array size is 21 to accommodate indices from 0 to 20
    
    // Loop to read n integers and count their occurrences
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        // Increment the count for the input integer adjusted by +10 to handle negative values
        cnt[num + 10]++;
    }
    
    // Variable to store the final result
    long res = 0;
    
    // Calculate the number of pairs (i, 20 - i) where i ranges from 0 to 9
    for (int i = 0; i < 10; i++) {
        // Multiply the counts of i and (20 - i) and add to the result
        res += cnt[i] * cnt[20 - i];
    }
    
    // Add the number of pairs of the integer 10 (i.e., combinations of 10 taken 2 at a time)
    res += (cnt[10] * (cnt[10] - 1)) / 2;
    
    // Output the final result
    printf("%ld\n", res);
    
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
