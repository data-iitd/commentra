
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 1: Read the input value N, which represents the number of elements.
    int N;
    scanf("%d", &N);

    // Step 2: Create a map idorder to store the elements and their corresponding positions.
    int *idorder = (int *)malloc(N * sizeof(int));

    // Step 3: Read each element and store its value and position in the map.
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        idorder[A - 1] = i + 1;
    }

    // Step 4: Print the positions of the elements in the order they were read.
    for (int i = 0; i < N; i++) {
        printf("%d ", idorder[i]);
    }

    // Free the memory allocated for idorder.
    free(idorder);

    return 0;
}
