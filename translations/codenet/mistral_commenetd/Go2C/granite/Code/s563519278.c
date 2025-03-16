

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variable N to store the number of elements in the array
    int N;
    scanf("%d", &N); // Read the number of elements from the standard input

    // Initialize an array 'v' of size N to store the frequency of each element
    int *v = (int *)malloc(N * sizeof(int));

    // Iterate through the input elements and update the frequency in the array 'v'
    for (int i = 1; i < N; i++) {
        int a;
        scanf("%d", &a); // Read the next element from the standard input
        // Update the frequency of the element 'a-1' in the array 'v'
        v[a-1]++;
    }

    // Iterate through the array 'v' and print each element to the standard output
    for (int i = 0; i < N; i++) {
        printf("%d\n", v[i]); // Print each element to the standard output
    }

    // Free the memory allocated for the array 'v'
    free(v);

    // End of the code
    return 0;
}
