#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} Pair;

int compare(const void *a, const void *b) {
    Pair *pairA = (Pair *)a;
    Pair *pairB = (Pair *)b;
    return pairB->second - pairA->second;
}

int main() {
    int n;
    scanf("%d", &n);
    Pair m[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m[i].first, &m[i].second);
    }
    qsort(m, n, sizeof(Pair), compare);
    Pair a = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i].second > a.second) {
            printf("Happy Alex\n");
            return 0;
        }
        a = m[i];
    }
    printf("Poor Alex\n");
    return 0;
}

