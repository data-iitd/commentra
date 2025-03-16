#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) (x), (x) + (n)

typedef long long ll;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int n;
    scanf("%d", &n);

    int a[n];
    REP(i, n) scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), compare);

    REP(i, n - 1) {
        if (a[i] == a[i + 1]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}
