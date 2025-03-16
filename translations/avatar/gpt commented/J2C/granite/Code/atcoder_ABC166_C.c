
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    // Read the number of elements (N) and the number of comparisons (M)
    int N, M;
    scanf("%d %d", &N, &M);
    
    // Initialize an array to hold the heights and a boolean array to track valid heights
    int *H = (int*)malloc(N * sizeof(int));
    int *ans = (int*)malloc(N * sizeof(int));
    
    // Read the heights and initialize the ans array to true
    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]); // Read the height for each element
        ans[i] = 1; // Assume all heights are valid initially
    }
    
    // Process M comparisons between pairs of heights
    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2); // Read the first index for comparison and the second index for comparison
        
        // Compare the heights and update the ans array based on the comparison results
        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = 0; // temp1 is shorter, mark it as invalid
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = 0; // temp2 is shorter, mark it as invalid
        } else {
            // If heights are equal, mark both as invalid
            ans[temp1 - 1] = 0;
            ans[temp2 - 1] = 0;
        }
    }
    
    // Count the number of valid heights
    int ans2 = 0;
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            ans2++; // Increment count for each valid height
        }
    }
    
    // Output the count of valid heights
    printf("%d\n", ans2);
    
    // Free memory allocated for arrays
    free(H);
    free(ans);
    
    return 0;
}
