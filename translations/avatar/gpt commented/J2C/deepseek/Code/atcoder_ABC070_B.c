#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (c > b) {
        printf("0\n");
    } else if (a > d) {
        printf("0\n");
    } else if (a < c) {
        printf("%d\n", (b < d) ? b - c : d - c);
    } else {
        int arr[4];
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;

        qsort(arr, 4, sizeof(int), (int (*)(const void *, const void *))compare);

        printf("%d\n", arr[2] - arr[1]);
    }

    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
