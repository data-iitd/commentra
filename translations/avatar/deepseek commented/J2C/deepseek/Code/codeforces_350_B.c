#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n + 1], b[n + 1], num[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }

    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; i++) {
        num[b[i]]++;
    }

    char ss[1000];
    int ans = 0;
    int st[n + 1];
    memset(st, 0, sizeof(st));

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = 1;
            char temp[10];
            sprintf(temp, "%d", i);
            char sss[10];
            strcpy(sss, temp);
            strcat(ss, " ");
            strcat(ss, strrev(sss));
            int s = 1;

            int x = b[i];
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {
                sprintf(temp, "%d", x);
                strcat(ss, " ");
                strcat(ss, strrev(temp));
                st[x] = 1;
                x = b[x];
                s++;
            }

            if (s > ans) {
                ans = s;
                char *reversed = strdup(ss);
                reversed = strrev(reversed);
                strcpy(ss, reversed);
            }
        }
    }

    printf("%d\n", ans);
    printf("%s\n", ss);

    return 0;
}
