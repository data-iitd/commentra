#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000

// Function to read an integer from input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers and return the count of unique elements
int read_list(int *A) {
    int N = read_int();
    int unique_count = 0;
    int last = -1;

    for (int i = 0; i < N; i++) {
        int current;
        scanf("%d", &current);
        if (current != last) {
            A[unique_count++] = current;
            last = current;
        }
    }
    return unique_count;
}

int main() {
    int A[MAX_N];
    
    // Read the list of integers and get the count of unique elements
    int N = read_list(A);

    // Initialize the index and answer counter
    int i = 1;
    int ans = 0;

    // Loop through the list to count the number of peaks and valleys
    while (i < N - 1) {
        // Check if the current element is a peak or a valley
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans++;  // Increment the answer for each peak/valley found
            i++;    // Skip the next element to avoid double counting
        }
        i++;  // Move to the next element
    }

    // Print the total count of peaks and valleys plus one
    printf("%d\n", ans + 1);

    return 0;
}

// <END-OF-CODE>
