#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; // Step 1: Reading the number of elements (N)
    scanf("%d", &N);
    int *v = (int *)malloc(N * sizeof(int)); // Step 3: Initializing the array
    int a;

    for (int i = 1; i < N; i++) { // Step 4: Reading and counting elements
        scanf("%d", &a);
        v[a - 1]++;
    }

    for (int i = 0; i < N; i++) { // Step 5: Writing the results
        printf("%d\n", v[i]);
    }

    free(v);
    return 0;
}
