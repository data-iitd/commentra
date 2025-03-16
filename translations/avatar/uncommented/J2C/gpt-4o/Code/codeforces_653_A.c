#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Remove duplicates
    int *unique = (int *)malloc(n * sizeof(int));
    int unique_count = 0;

    for (int i = 0; i < n; i++) {
        bool is_duplicate = false;
        for (int j = 0; j < unique_count; j++) {
            if (a[i] == unique[j]) {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate) {
            unique[unique_count++] = a[i];
        }
    }

    // Sort the unique elements
    qsort(unique, unique_count, sizeof(int), compare);

    bool found = false;
    for (int i = 0; i < unique_count - 2; i++) {
        if (unique[i] + 1 == unique[i + 1] && unique[i + 1] + 1 == unique[i + 2]) {
            found = true;
            break;
        }
    }

    printf(found ? "YES\n" : "NO\n");

    free(a);
    free(unique);
    return 0;
}

// <END-OF-CODE>
