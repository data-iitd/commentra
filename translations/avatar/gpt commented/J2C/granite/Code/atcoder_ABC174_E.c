
#include <stdio.h>
#include <stdlib.h>

int nei(int mid, int* logsLength, int k, int n) {
    int i;
    for (i = 0; i < n; i++) {
        k -= (logsLength[i] + mid - 1) / mid - 1;
        if (k < 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int* logsLength = (int*)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &logsLength[i]);
    }
    int min = 1, max = 1000000000;
    while (min < max) {
        int mid = (min + max) / 2;
        if (nei(mid, logsLength, k, n)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    printf("%d\n", min);
    free(logsLength);
    return 0;
}
