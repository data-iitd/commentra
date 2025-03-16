#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); // Reading the number of elements in the array from the standard input
    int A[N];

    // Reading the elements of the array from the standard input
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]); // Reading the i-th element of the array from the standard input
    }

    int count = 0; // Initializing the count variable to zero

    // Iterating through the array to find the number of increasing and decreasing sequences
    for (int i = 0; i < N - 1; i++) { // Iterating up to the second last index of the array
        if (i == N - 1) count++; // If we have reached the last index, increment the count
        else if (A[i] == A[i + 1]) ; // If the current and next elements are equal, do nothing
        else if (A[i] < A[i + 1]) { // If the current element is less than the next element
            while (A[i] <= A[i + 1]) { // Finding the length of the increasing sequence
                i++;
                if (i == N - 1) break; // If we have reached the last index, break the loop
            }
            count++; // Increment the count after finding the length of the increasing sequence
        } else { // If the current element is greater than the next element
            while (A[i] >= A[i + 1]) { // Finding the length of the decreasing sequence
                i++;
                if (i == N - 1) break; // If we have reached the last index, break the loop
            }
            count++; // Increment the count after finding the length of the decreasing sequence
        }
    }

    printf("%d\n", count); // Printing the final count
    return 0;
}

