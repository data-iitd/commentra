
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N; // Read the number of elements in the memory array from the standard input
    scanf("%d", &N);

    int mem[N + 1]; // Allocate memory for an integer array of size N+1 to store the memory locations of each process

    for (int i = 1; i <= N; ++i) { // Read the memory locations of each process and store them in the mem array
        int P;
        scanf("%d", &P);
        mem[P] = i;
    }

    int maxcnt = 1; // Initialize maxcnt to 1, which will store the maximum length of a consecutive increasing sequence of memory locations
    int cnt = 1; // Initialize cnt to 1, which will store the current length of such a sequence

    for (int i = 1; i < N; ++i) { // Traverse the mem array and update maxcnt and cnt variables accordingly
        if (mem[i] < mem[i + 1]) {
            cnt++;
        } else {
            maxcnt = max(maxcnt, cnt);
            cnt = 1;
        }
    }

    // Update maxcnt with the length of the last consecutive increasing sequence
    maxcnt = max(maxcnt, cnt);

    printf("%d\n", N - maxcnt); // Print the result N - maxcnt to the standard output
    return 0; // Return 0 from the main function to indicate successful execution
}

