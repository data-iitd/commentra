
#include <stdio.h> // Include the standard input/output library

int main() {
    int N, M; // Declare variables N and M to store the number of elements and comparisons
    scanf("%d %d", &N, &M); // Read the number of elements N and comparisons M from the input
    
    int H[N]; // Declare an array H to store the heights of N elements
    int ans[N]; // Declare an array ans to store the result for each element
    
    // Read the heights of the elements into the array H
    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
        ans[i] = 1; // Initialize all elements in the array ans to 1
    }
    
    // Read the pairs of indices (temp1 and temp2) and compare the heights at these indices
    for (int i = 0; i < M; i++) {
        int temp1, temp2; // Declare variables temp1 and temp2 to store the indices
        scanf("%d %d", &temp1, &temp2);
        
        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = 0; // Update the array ans based on the comparison results
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = 0; // Update the array ans based on the comparison results
        } else {
            ans[temp1 - 1] = 0; // Update the array ans based on the comparison results
            ans[temp2 - 1] = 0; // Update the array ans based on the comparison results
        }
    }
    
    int ans2 = 0; // Declare a variable ans2 to count the number of elements in the array ans that are still 1
    // Count the number of elements in the array ans that are still 1
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            ans2++; // Increment the counter if the element is still 1
        }
    }
    
    printf("%d\n", ans2); // Print the count
    
    return 0; // Return 0 to indicate successful execution
}
