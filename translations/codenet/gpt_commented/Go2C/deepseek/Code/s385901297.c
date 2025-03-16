#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int ns[4];
    int i;

    // Read four integers from standard input
    scanf("%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3]);

    // Sort the array using qsort and the compare function
    qsort(ns, 4, sizeof(int), compare);

    // Check if the sorted integers match the specific sequence [1, 4, 7, 9]
    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        // If they match, print "YES"
        printf("YES\n");
    } else {
        // If they do not match, print "NO"
        printf("NO\n");
    }

    return 0;
}
