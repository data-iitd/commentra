#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // Sort in descending order
}

int main() {
    int in[3];
    scanf("%d %d %d", &in[0], &in[1], &in[2]);
    
    qsort(in, 3, sizeof(int), compare);

    printf("%d\n", in[0] * 10 + in[1] + in[2]);
    return 0;
}

// <END-OF-CODE>
