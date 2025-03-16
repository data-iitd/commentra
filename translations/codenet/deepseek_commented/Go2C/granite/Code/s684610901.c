
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int index;
    int p1;
    int p2;
} pair;

typedef struct {
    int *array;
    int size;
} Int64Slice;

void Int64s(int *a, int size) {
    qsort(a, size, sizeof(int), compare);
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    if (C >= A && C <= B) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

