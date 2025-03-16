
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    fgets(s, 100001, stdin);
    int cum[100001] = {0};
    int i;
    for (i = 1; s[i]!= '\0'; i++) {
        cum[i] = cum[i - 1] + (s[i] == s[i - 1]);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", cum[r - 1] - cum[l - 1]);
    }
    return 0;
}
