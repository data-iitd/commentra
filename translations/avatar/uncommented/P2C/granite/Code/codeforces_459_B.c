
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *l1 = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l1[i]);
    }
    int a = l1[0], b = l1[0];
    for (int i = 1; i < n; i++) {
        if (l1[i] > a) {
            a = l1[i];
        }
        if (l1[i] < b) {
            b = l1[i];
        }
    }
    int ac = 0, bc = 0;
    for (int i = 0; i < n; i++) {
        if (l1[i] == a) {
            ac++;
        }
        if (l1[i] == b) {
            bc++;
        }
    }
    printf("%d %d\n", a - b, ac * bc);
    free(l1);
    return 0;
}

