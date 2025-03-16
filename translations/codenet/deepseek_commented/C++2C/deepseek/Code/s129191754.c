#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define all(x) x, x + n
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    REP(i, n) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    bool has_duplicates = false;
    REP(i, n - 1) {
        if (a[i] == a[i + 1]) {
            has_duplicates = true;
            break;
        }
    }
    if (has_duplicates) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}
