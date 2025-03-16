#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 200000 + 10
#define INF 100000000

int maps[MAXN];
int num[MAXN];

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &maps[i]);
            num[i] = maps[i];
        }
        qsort(maps + 1, n, sizeof(int), compare);
        int m = n / 2;
        for (int i = 1; i <= n; i++) {
            if (num[i] <= maps[m + 1])
                printf("%d\n", maps[m + 2]);
            else
                printf("%d\n", maps[m + 1]);
        }
    }
    return 0;
}
