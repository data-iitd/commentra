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
        int l[4];
        l[0] = a;
        l[1] = b;
        l[2] = c;
        l[3] = d;
        qsort(l, 4, sizeof(int), (int (*)(const void *, const void *))compare);
        printf("%d\n", l[2] - l[1]);
    }
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
