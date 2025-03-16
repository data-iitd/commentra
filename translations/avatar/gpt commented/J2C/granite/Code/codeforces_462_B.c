
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int left;
} c462b;

int cmpfunc (const void * a, const void * b) {
   return (((c462b*)a)->left - ((c462b*)b)->left);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    c462b* cards = (c462b*)malloc(sizeof(c462b) * 26);
    for (int i = 0; i < 26; i++) {
        cards[i].left = 0;
    }

    char s[n];
    scanf("%s", s);
    for (int t = 0; t < n; t++) {
        cards[s[t] - 'A'].left++;
    }

    long ans = 0;
    for (int i = 0; i < k; i++) {
        qsort(cards, 26, sizeof(c462b), cmpfunc);

        long change = cards[25].left;
        if (change > k - i) {
            change = k - i;
        }
        ans += change * change;
        cards[25].left -= change;
        i += change - 1;
    }

    printf("%ld\n", ans);

    free(cards);
    return 0;
}

