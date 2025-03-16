
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int cum[100001] = {0};
    for (int i = 1; i < strlen(s); i++) {
        if (s[i] == s[i - 1]) {
            cum[i] = cum[i - 1] + 1;
        } else {
            cum[i] = cum[i - 1];
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", cum[r - 1] - cum[l - 2]);
    }
    return 0;
}
//END-OF-CODE