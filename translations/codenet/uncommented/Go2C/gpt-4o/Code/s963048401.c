#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *as = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(n * sizeof(int));
    int len_xs = 0;

    for (int j = 0; j < n; j++) {
        int key = as[j];
        int *pos = (int *)bsearch(&key, xs, len_xs, sizeof(int), compare);
        
        if (pos == NULL) {
            xs[len_xs++] = key;
            qsort(xs, len_xs, sizeof(int), compare);
        } else {
            *pos = key;
        }
    }

    printf("%d\n", len_xs);

    free(as);
    free(xs);
    return 0;
}

// <END-OF-CODE>
