

#include <stdio.h>

int main() {
    int N;  // Read the integer input N
    scanf("%d", &N);
    
    int A[N];  // Read the list of integers A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    // Initialize variables to track the minimum and maximum indices where the condition is true
    int mn = N + 1, mx = -1;
    
    // Iterate over the range of N to find the indices where the condition is true
    for (int i = 0; i < N; i++) {
        if (i + 1!= A[i]) {
            mn = mn < i? mn : i;  // Update mn if a smaller index is found
            mx = mx > i? mx : i;  // Update mx if a larger index is found
        }
    }
    
    // Check if no indices satisfy the condition
    if (mx == -1) {
        printf("0 0\n");  // Print '0 0' if no indices satisfy the condition
    } else {
        // Reverse the sublist from index mn to mx + 1 and update A
        for (int i = mn; i <= mx; i++) {
            int temp = A[i];
            A[i] = A[mn + mx - i];
            A[mn + mx - i] = temp;
        }
        
        // Check if the list A is sorted
        int isSorted = 1;
        for (int i = 0; i < N - 1; i++) {
            if (A[i] > A[i + 1]) {
                isSorted = 0;
                break;
            }
        }
        
        if (isSorted) {
            printf("%d %d\n", mn + 1, mx + 1);  // Print the indices if A is sorted
        } else {
            printf("0 0\n");  // Print '0 0' if A is not sorted
        }
    }
    
    return 0;
}
