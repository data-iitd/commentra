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
    for (int i = 1; i <= n; i++) {
        num[b[i]]++;
    }
    char ss[10000];
    int ans = 0;
    int st[n + 1];
    memset(st, 0, sizeof(st));
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = 1;
            char temp[100];
            sprintf(temp, "%d", i);
            char temp2[100];
            sprintf(temp2, "%d", b[i]);
            int s = 1;
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {
                char temp3[100];
                sprintf(temp3, "%d", x);
                strcat(temp, " ");
                strcat(temp, temp3);
                st[x] = 1;
                x = b[x];
                s++;
            }
            if (s > ans) {
                ans = s;
                strcpy(ss, temp);
            }
        }
    }
    printf("%d\n%s\n", ans, ss);
    return 0;
}
