

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n + 1];
    int b[n + 1];
    int num[n + 1];

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    char ss[100000];
    int ans = 0;
    bool st[n + 1];

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = true;
            char sb[100000];
            int x = b[i];
            char sss[100];
            sprintf(sss, "%d", i);
            strcat(sb, sss);
            int s = 1;

            while (st[x] == false && num[x] == 1 && x!= 0 && a[x]!= 1) {
                sprintf(sss, "%d", x);
                strcat(sb, sss);
                st[x] = true;
                x = b[x];
                s++;
            }

            if (s > ans) {
                ans = s;
                strcpy(ss, sb);
            }
        }
    }

    printf("%d\n", ans);
    printf("%s\n", ss);

    return 0;
}

