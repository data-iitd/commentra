#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int s[11], i;
    for(i = 0; i < 10; i++) {
        scanf("%d", &s[i]);
    }
    qsort(s, 10, sizeof(int), compare);
    for(i = 9; i > 6; i--) {
        printf("%d\n", s[i]);
    }
    return 0;
}

// <END-OF-CODE>
