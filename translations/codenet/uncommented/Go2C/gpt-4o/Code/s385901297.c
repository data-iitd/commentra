#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int ns[4];
    
    // Read input
    scanf("%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3]);

    // Sort the array
    qsort(ns, 4, sizeof(int), compare);

    // Check the condition
    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
