
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char s[n];
    scanf("%s", s);
    int cards[26] = {0};
    for (int i = 0; i < n; i++) {
        cards[s[i] - 'A']++;
    }
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        int change = 0;
        for (int j = 0; j < 26; j++) {
            if (cards[j] > 0) {
                change++;
                cards[j]--;
                if (change == k - i) {
                    break;
                }
            }
        }
        ans += change * change;
    }
    printf("%lld\n", ans);
    return 0;
}

