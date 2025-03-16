#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);  // Take an integer input for the number of elements
    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);  // Take a list of integers as input
    }
    qsort(l, n, sizeof(int), compare);  // Sort the list of integers

    // Check if there exists any integer i in the list such that i + 1 and i + 2 are also in the list
    for (int i = 0; i < n; i++) {
        if (bsearch(&(l[i] + 1), l, n, sizeof(int), compare) != NULL && bsearch(&(l[i] + 2), l, n, sizeof(int), compare) != NULL) {
            printf("YES\n");  // If found, print 'YES' and break the loop
            return 0;
        }
    }
    printf("NO\n");  // If no such integer is found, print 'NO'
    return 0;
}

