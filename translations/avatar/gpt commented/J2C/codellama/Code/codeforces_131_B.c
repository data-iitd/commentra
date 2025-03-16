#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    int n; // Declare variable to store the number of integers to process
    scanf("%d", &n); // Read the number of integers to process
    
    // Initialize an array to count occurrences of integers in the range [-10, 10]
    long cnt[21]; // Array size is 21 to accommodate indices from 0 to 20
    
    // Loop to read n integers and count their occurrences
    for (int i = 0; i < n; i++) {
        // Increment the count for the input integer adjusted by +10 to handle negative values
        cnt[scanf("%d", &i) + 10]++;
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
    
    // End of code
    return 0;
}


