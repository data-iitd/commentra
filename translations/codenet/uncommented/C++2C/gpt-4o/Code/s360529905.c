#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int *a, *b, i, N;
    int frontHalf, backHalf;
<<<<<<< HEAD
    scanf("%d", &N);
    a = (int *)malloc(N * sizeof(int));
    b = (int *)malloc(N * sizeof(int));
=======
    
    scanf("%d", &N);
    a = (int *)malloc(N * sizeof(int));
    b = (int *)malloc(N * sizeof(int));
    
>>>>>>> 98c87cb78a (data updated)
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
<<<<<<< HEAD
    qsort(b, N, sizeof(int), compare);
    frontHalf = b[N / 2 - 1];
    backHalf = b[N / 2];
    free(b);
=======
    
    qsort(b, N, sizeof(int), compare);
    
    frontHalf = b[N / 2 - 1];
    backHalf = b[N / 2];
    
    free(b);
    
>>>>>>> 98c87cb78a (data updated)
    for (i = 0; i < N; i++) {
        if (a[i] < backHalf)
            printf("%d\n", backHalf);
        else
            printf("%d\n", frontHalf);
    }
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    free(a);
    return 0;
}

// <END-OF-CODE>
