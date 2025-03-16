#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int ns[4];
    int i;

    for (i = 0; i < 4; i++) {
        scanf("%d", &ns[i]);
    }

    qsort(ns, 4, sizeof(int), compare);

    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

