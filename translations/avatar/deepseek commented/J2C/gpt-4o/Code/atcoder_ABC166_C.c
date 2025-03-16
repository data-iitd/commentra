#include <stdio.h> // Include standard input-output library
#include <stdbool.h> // Include library for boolean type

int main() {
    int N; // Number of elements
    long M; // Number of comparisons
    scanf("%d", &N); // Read the number of elements N
    scanf("%ld", &M); // Read the number of comparisons M
    
    long H[N]; // Array to store the heights of N elements
    bool ans[N]; // Array to store the result for each element
    
    // Read the heights of the elements into the array H
    for (int i = 0; i < N; i++) {
        scanf("%ld", &H[i]);
        ans[i] = true; // Initialize all elements in the boolean array ans to true
    }
    
    // Read the pairs of indices (temp1 and temp2) and compare the heights at these indices
    for (long i = 0; i < M; i++) {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        
        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = false; // Update the boolean array ans based on the comparison results
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = false; // Update the boolean array ans based on the comparison results
        } else {
            ans[temp1 - 1] = false; // Update the boolean array ans based on the comparison results
            ans[temp2 - 1] = false; // Update the boolean array ans based on the comparison results
        }
    }
    
    int ans2 = 0; // Counter to count the number of elements in the boolean array ans that are still true
    // Count the number of elements in the boolean array ans that are still true
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            ans2++; // Increment the counter if the element is still true
        }
    }
    
    printf("%d\n", ans2); // Print the count
    return 0; // Return success
}

// <END-OF-CODE>
