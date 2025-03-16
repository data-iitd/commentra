#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *l = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    
    qsort(l, n, sizeof(int), compare);
    
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] > c) {
            c++;
        }
    }
    
    printf("%d\n", c + 1);
    
    free(l);
    return 0;
}

// <END-OF-CODE>
