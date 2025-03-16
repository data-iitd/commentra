#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int l1[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l1[i]);
    }
    qsort(l1, n, sizeof(int), compare);
    int a = l1[n - 1];
    int b = l1[0];
    if (a == b) {
        printf("%d %d\n", a - b, n * (n - 1) / 2);
    } else {
        int ac = 0, bc = 0;
        for (int i = 0; i < n; i++) {
            if (l1[i] == a) ac++;
            if (l1[i] == b) bc++;
        }
        printf("%d %d\n", a - b, ac * bc);
    }
    return 0;
}
