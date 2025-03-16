#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a; // Sort in descending order
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *lst = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }
    
    qsort(lst, n, sizeof(int), compare);
    
    int od = 0;
    for (int i = 0; i < n; i++) {
        if (lst[i] & 1) {
            od++;
        }
    }
    
    int sum = 0;
    int ok = 0;
    for (int i = 0; i < n; i++) {
        if (lst[i] % 2 == 0) {
            sum += lst[i];
        } else {
            if (ok || od > 1) {
                sum += lst[i];
                od--;
                ok = !ok;
            }
        }
    }
    
    printf("%d\n", sum);
    
    free(lst);
    return 0;
}

// <END-OF-CODE>
