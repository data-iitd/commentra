#include <stdio.h>

void editorial(int N, int P[]) {
    // If there is only one element, the answer is 0 (no removals needed)
    if (N == 1) {
        printf("0\n");
        return;
    }
    
    // Create an array to store the positions of elements in P
    int a[N + 1];
    for (int i = 0; i <= N; i++) {
        a[i] = 0;
    }
    
    // Fill the array 'a' with the indices of the elements in P
    for (int i = 0; i < N; i++) {
        a[P[i]] = i;
    }
    
    // Initialize temporary length and maximum length variables
    int tmp = 1;
    int max_len = 1;
    
    // Iterate through the array to find the longest increasing subsequence
    for (int i = 1; i < N; i++) {
        if (a[i] < a[i + 1]) {
            tmp++;  // Increase the temporary length if the sequence is increasing
            if (tmp > max_len) {
                max_len = tmp;  // Update the maximum length found
            }
        } else {
            tmp = 1;  // Reset temporary length if the sequence is not increasing
        }
    }
    
    // Calculate the answer as the total elements minus the length of the longest subsequence
    int ans = N - max_len;
    printf("%d\n", ans);
}

void WA(int N, int P[]) {
    // Initialize temporary length and answer variables
    int tmp = 0;
    int ans = 0;
    
    // Iterate through the list P to find the longest consecutive subsequence
    for (int i = 0; i < N; i++) {
        // Check if the current element is consecutive to the previous one
        if (i == 0 || P[i - 1] + 1 == P[i]) {
            tmp++;  // Increase temporary length for consecutive elements
        } else {
            if (tmp > ans) {
                ans = tmp;  // Update the answer with the maximum found
            }
            tmp = 1;  // Reset temporary length for a new sequence
        }
    }
    
    // Print the result as the total elements minus the longest consecutive subsequence
    printf("%d\n", N - ans);
}

int main() {
    // Read the number of elements from user input
    int N;
    scanf("%d", &N);
    
    // Read N integers from user input and store them in a list P
    int P[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }
    
    // Call the editorial function to process the input
    editorial(N, P);
    
    return 0;
}

// <END-OF-CODE>
