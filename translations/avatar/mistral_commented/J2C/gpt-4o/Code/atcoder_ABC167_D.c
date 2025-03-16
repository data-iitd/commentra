#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX 2147483647
#define LMAX 9223372036854775807
#define LEN (int)(1e6 + 1)

void doIt() {
    int N;
    long K;
    scanf("%d", &N); // Reading the number of elements in the array
    scanf("%ld", &K); // Reading the long value K
    int *A = (int *)malloc(N * sizeof(int)); // Creating an integer array A of size N

    // Reading the elements of the array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i]--; // Subtracting 1 from the input to get the index of the previous element
    }

    int *used = (int *)calloc(N, sizeof(int)); // Creating an array to track used indices
    int *idx = (int *)malloc(N * sizeof(int)); // Creating an integer array named idx
    int *pos = (int *)malloc(N * sizeof(int)); // Creating an integer array named pos
    int next = 0, cur = 0; // Initializing the variables next and cur

    // Finding the cycle starting point using BFS
    while (!used[next]) {
        used[next] = 1; // Marking the current index as used
        idx[next] = cur; // Storing the current position in the idx array
        pos[cur] = next; // Storing the previous position in the pos array
        next = A[next]; // Moving to the next index
        cur++; // Incrementing the current position
    }

    long a = (long)cur - idx[next]; // Calculating the length of the cycle
    long b = (long)idx[next]; // Calculating the starting position of the cycle in the array
    int ans = (int)((10000 * a + K - b + MOD) % a + b); // Calculating the answer using the formula

    // Checking if the starting position of the cycle is greater than K, if yes then the answer is K
    if (b > K) {
        ans = (int)K;
    }

    printf("%d\n", pos[ans] + 1); // Printing the position of the answer in the array

    // Free allocated memory
    free(A);
    free(used);
    free(idx);
    free(pos);
}

int main() {
    doIt(); // Calling the doIt() function to execute the logic of the program
    return 0;
}

// <END-OF-CODE>
