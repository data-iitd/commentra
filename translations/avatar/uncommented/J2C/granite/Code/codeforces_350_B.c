
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n+1], b[n+1], num[n+1];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) num[b[i]]++;
    char ss[100000];
    int ans = 0;
    bool st[n+1];
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = true;
            char s[100000];
            int x = b[i], s = 1;
            sprintf(s, "%d", i);
            strcat(ss, s);
            while (!st[x] && num[x] == 1 && x!= 0 && a[x]!= 1) {
                sprintf(s, "%d", x);
                strcat(ss, s);
                st[x] = true;
                x = b[x];
                s++;
            }
            if (s > ans) {
                ans = s;
                strcpy(ss, s);
            }
        }
    }
    printf("%d\n%s\n", ans, ss);
    return 0;
}
//END-OF-CODE