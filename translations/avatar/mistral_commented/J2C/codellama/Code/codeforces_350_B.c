
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, j, a[1000], b[1000], num[1000], x, s, ans;
    char ss[1000];
    bool st[1000];

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        num[i] = 1;
        st[i] = false;
    }

    for (i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = true;
            sprintf(ss, "%d", i);
            x = b[i];
            s = 1;

            while (st[x] == false && num[x] == 1 && x != 0 && a[x] != 1) {
                sprintf(ss, "%s %d", ss, x);
                st[x] = true;
                x = b[x];
                s++;
            }

            if (s > ans) {
                ans = s;
                strcpy(ss, ss + strlen(ss) - s);
            }
        }
    }

    printf("%d\n%s\n", ans, ss);

    return 0;
}

