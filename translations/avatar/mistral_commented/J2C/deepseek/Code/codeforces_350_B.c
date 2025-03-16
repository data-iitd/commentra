#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int main() {
    int n;
    scanf("%d", &n);

    int a[MAX_N + 1];
    int b[MAX_N + 1];
    int num[MAX_N + 1];
    int ans = 0;
    char ss[2 * MAX_N + 1];
    int st[MAX_N + 1];

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    memset(st, 0, sizeof(st));
    strcpy(ss, "");

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = 1;
            char temp_ss[2 * MAX_N + 1];
            strcpy(temp_ss, "");
            int x = b[i];
            char current[10];
            sprintf(current, "%d", i);
            strcat(temp_ss, " ");
            strcat(temp_ss, strrev(current));
            int s = 1;

            while (st[x] == 0 && num[x] == 1 && x != 0 && a[x] != 1) {
                char current[10];
                sprintf(current, "%d", x);
                strcat(temp_ss, " ");
                strcat(temp_ss, strrev(current));
                st[x] = 1;
                x = b[x];
                s++;
            }

            if (s > ans) {
                ans = s;
                strcpy(ss, strrev(temp_ss));
            }
        }
    }

    printf("%d\n", ans);
    printf("%s\n", ss);

    return 0;
}

