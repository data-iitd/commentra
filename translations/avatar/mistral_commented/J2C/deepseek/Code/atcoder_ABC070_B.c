#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (c > b) {
        printf("0\n");
        return 0;
    }

    if (a > d) {
        printf("0\n");
        return 0;
    }

    if (a < c) {
        int difference = (b < d) ? b - c : d - c;
        printf("%d\n", difference);
        return 0;
    }

    int arr[4] = {a, b, c, d};
    qsort(arr, 4, sizeof(int), (int (*)(const void *, const void *))compare);

    int difference = arr[2] - arr[1];
    printf("%d\n", difference);

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
