#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

const char* s() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    qsort(a, n, sizeof(int), compare);
    
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            free(a);
            return "YES";
        }
    }
    
    free(a);
    return "NO";
}

int main() {
    printf("%s\n", s());
    return 0;
}

// <END-OF-CODE>
