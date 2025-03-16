#include <stdio.h>
#include <stdlib.h>

void editorial(int N, int *P) {
    // Base case: if there is only one element in the list, the answer is 0.
    if (N == 1) {
        printf("0\n");
        return;
    }
    
    // Initialize an array a of size N+1 with all elements initialized to 0.
    int *a = (int *)calloc(N + 1, sizeof(int));
    
    // Iterate through the list P and assign each element its index in the array a.
    for (int i = 0; i < N; i++) {
        a[P[i]] = i;
    }
    
    // Initialize two variables: tmp to keep track of the current streak,
    // and max_len to keep track of the maximum streak.
    int tmp = 1;
    int max_len = 1;
    
    // Iterate through the array a from the second element to the last.
    for (int i = 1; i < N; i++) {
        // If the current element has a smaller index than the previous one,
        // increment the streak and update max_len if necessary.
        if (a[i] < a[i + 1]) {
            tmp++;
            if (tmp > max_len) {
                max_len = tmp;
            }
        } else {
            // Otherwise, reset the streak to 1.
            tmp = 1;
        }
    }
    
    // Calculate the answer as the difference between the total number of elements
    // and the maximum streak.
    int ans = N - max_len;
    // Print the answer.
    printf("%d\n", ans);
    
    // Free the allocated memory for array a.
    free(a);
}

int main() {
    // Read the number of test cases N from the standard input.
    int N;
    scanf("%d", &N);
    
    // Read N integers from the standard input and store them in a list P.
    int *P = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }
    
    // Call the editorial function with N and P as arguments.
    editorial(N, P);
    
    // Free the allocated memory for array P.
    free(P);
    
    return 0;
}

// <END-OF-CODE>
