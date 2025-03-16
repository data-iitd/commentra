#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool all_same(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int *elems = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }

    if (all_same(elems, n)) {
        printf("0\n");
        free(elems);
        return 0;
    }

    if (k == 1) {
        printf("-1\n");
        free(elems);
        return 0;
    }

    if (!all_same(elems + k - 1, n - (k - 1))) {
        printf("-1\n");
        free(elems);
        return 0;
    }

    int target = elems[n - 1];
    int to_delete_count = 0;

    for (int i = 0; i < k - 1; i++) {
        if (elems[i] == target) {
            to_delete_count++;
        } else {
            break;
        }
    }

    printf("%d\n", to_delete_count);
    free(elems);
    return 0;
}

// <END-OF-CODE>
