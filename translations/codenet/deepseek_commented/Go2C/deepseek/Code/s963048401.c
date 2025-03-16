#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int as[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int xs[MAX_N];
    int len = 1;
    xs[0] = as[0];

    for (int j = 1; j < n; j++) {
        int pos = 0;
        while (pos < len && xs[pos] < as[j]) {
            pos++;
        }
        if (pos == len) {
            xs[len++] = as[j];
        } else {
            xs[pos] = as[j];
        }
    }

    printf("%d\n", len);
    return 0;
}
