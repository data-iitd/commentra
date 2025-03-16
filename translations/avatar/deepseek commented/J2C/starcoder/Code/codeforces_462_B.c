#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int n, k, i, t, change, ans;
    char s[100000];
    scanf("%d %d", &n, &k);
    for (i = 0; i < 26; i++) {
        c462b cards[26];
        for (t = 0; t < 26; t++) {
            cards[t].left = 0;
        }
    }
    scanf("%s", s);
    for (t = 0; t < n; t++) {
        cards[s[t] - 'A'].left++;
    }
    ans = 0;
    for (i = 0; i < k; i++) {
        qsort(cards, 26, sizeof(c462b), compare);
        change = cards[25].left < k - i? cards[25].left : k - i;
        ans += change * change;
        cards[25].left -= change;
        i += change - 1;
    }
    printf("%ld\n", ans);
    return 0;
}

struct c462b {
    int left;
};

int compare(const void *a, const void *b) {
    return ((c462b *) a)->left - ((c462b *) b)->left;
}

