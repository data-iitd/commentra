#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int main() {
    int N;
    scanf("%d", &N);
    
    int *idorder = (int *)malloc((N + 1) * sizeof(int));
    for (int i = 1; i <= N; i++) {
        int A;
        scanf("%d", &A);
        idorder[A] = i; // Store the order of the input
    }
    
    for (int i = 1; i <= N; i++) {
        printf("%d ", idorder[i]); // Print the order
    }
    
    free(idorder); // Free allocated memory
    return 0;
}

/* <END-OF-CODE> */
