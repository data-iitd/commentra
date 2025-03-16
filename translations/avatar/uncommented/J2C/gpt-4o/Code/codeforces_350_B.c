#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int main() {
    int n;
    scanf("%d", &n);
    
    int a[MAX_N + 1], b[MAX_N + 1], num[MAX_N + 1] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        num[b[i]]++;
    }

    char ss[MAX_N * 2] = ""; // To store the result string
    int ans = 0;
    int st[MAX_N + 1] = {0}; // To track visited nodes

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = 1;
            char sb[MAX_N * 2] = ""; // StringBuilder equivalent
            int x = b[i];
            char sss[20]; // Temporary string for reversing
            sprintf(sss, "%d", i);
            strcat(sb, sss);
            strcat(sb, " ");
            int s = 1;

            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {
                sprintf(sss, "%d", x);
                strcat(sb, sss);
                strcat(sb, " ");
                st[x] = 1;
                x = b[x];
                s++;
            }

            if (s > ans) {
                ans = s;
                // Reverse the string in sb and store in ss
                int len = strlen(sb);
                for (int j = 0; j < len; j++) {
                    ss[len - j - 1] = sb[j];
                }
                ss[len] = '\0'; // Null-terminate the string
            }
        }
    }

    printf("%d\n", ans);
    printf("%s\n", ss);
    
    return 0;
}
