#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Initialize variables
    int high = 1;
    int tower = n;
    int maximum = 1;

    // Sort the list
    qsort(l, n, sizeof(int), compare);

    // Loop through the sorted list
    for (int i = 1; i < n; i++) {
        if (l[i] == l[i - 1]) {
            tower -= 1;
            high += 1;
        } else {
            if (high > maximum) {
                maximum = high;
            }
            high = 1;
        }
    }

    if (high > maximum) {
        maximum = high;
    }

    // Print the result
    printf("%d %d\n", maximum, tower);

    return 0;
}
