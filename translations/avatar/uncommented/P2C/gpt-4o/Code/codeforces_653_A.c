#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *l = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    
    qsort(l, n, sizeof(int), compare);
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] + 1 == l[i + 1] && l[i] + 2 == l[i + 2]) {
            printf("YES\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("NO\n");
    }
    
    free(l);
    return 0;
}

// <END-OF-CODE>
