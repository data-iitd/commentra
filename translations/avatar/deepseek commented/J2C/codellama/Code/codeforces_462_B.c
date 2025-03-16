#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int left;
} c462b;

int compare(const void *a, const void *b) {
    return ((c462b *) a)->left - ((c462b *) b)->left;
}

int main() {
    int n, k, i, t;
    char s[100000];
    c462b cards[26];
    long ans = 0;
    scanf("%d %d", &n, &k);
    for (i = 0; i < 26; i++) {
        cards[i].left = 0;
    }
    scanf("%s", s);
    for (t = 0; t < n; t++) {
        cards[s[t] - 'A'].left++;
    }
    for (i = 0; i < k; i++) {
        qsort(cards, 26, sizeof(c462b), compare);
        long change = min(cards[25].left, k - i);
        ans += change * change;
        cards[25].left -= change;
        i += change - 1;
    }
    printf("%ld\n", ans);
    return 0;
}

