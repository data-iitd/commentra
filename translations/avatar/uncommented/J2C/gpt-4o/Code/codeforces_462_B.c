#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int left;
} c462b;

int compare(const void *a, const void *b) {
    return ((c462b *)a)->left - ((c462b *)b)->left;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    c462b cards[26];
    for (int i = 0; i < 26; i++) {
        cards[i].left = 0;
    }
    
    char s[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", s);
    
    for (int t = 0; t < n; t++) {
        cards[s[t] - 'A'].left++;
    }
    
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        qsort(cards, 26, sizeof(c462b), compare);
        long long change = (cards[25].left < k - i) ? cards[25].left : (k - i);
        ans += change * change;
        cards[25].left -= change;
        i += change - 1;
    }
    
    printf("%lld\n", ans);
    return 0;
}
