#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

int a[MAXN], b[MAXN], num[MAXN];
int n;
char ss[MAXN * 10];

void read_input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
}

void count_occurrences() {
    for (int i = 1; i <= n; i++) {
        num[b[i]]++;
    }
}

void find_longest_sequence() {
    int ans = 0;
    char ss[MAXN * 10];
    memset(ss, 0, sizeof(ss));
    bool st[MAXN] = {false};

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            st[i] = true;
            char temp_ss[MAXN * 10];
            int x = b[i];
            char sss[10];
            sprintf(sss, "%d", i);
            strcat(temp_ss, " ");
            strcat(temp_ss, sss);

            int s = 1;
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1) {
                char sss[10];
                sprintf(sss, "%d", x);
                strcat(temp_ss, " ");
                strcat(temp_ss, sss);
                st[x] = true;
                x = b[x];
                s++;
            }

            if (s > ans) {
                ans = s;
                strcpy(ss, temp_ss);
            }
        }
    }

    printf("%d\n", ans);
    printf("%s\n", ss);
}

int main() {
    read_input();
    count_occurrences();
    find_longest_sequence();
    return 0;
}
