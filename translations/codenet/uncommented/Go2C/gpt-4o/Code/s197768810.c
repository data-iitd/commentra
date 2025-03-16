#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *a = (int *)malloc(m * sizeof(int));
    if (a == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (sum > n) {
        printf("-1\n");
        free(a);
        return 0;
    }

    printf("%d\n", n - sum);
    free(a);
    return 0;
}

// <END-OF-CODE>
