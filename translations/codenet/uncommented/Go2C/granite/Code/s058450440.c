
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[5];
int ans = 0;

void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res;
        return;
    }
    for (int j = i; j < 5; j++) {
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char s[10];
    int dic[256] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        switch (s[0]) {
            case 'M':
                dic['M']++;
                break;
            case 'A':
                dic['A']++;
                break;
            case 'R':
                dic['R']++;
                break;
            case 'C':
                dic['C']++;
                break;
            case 'H':
                dic['H']++;
                break;
        }
    }
    int idx = 0;
    for (int i = 0; i < 256; i++) {
        if (dic[i] > 0) {
            a[idx++] = dic[i];
        }
    }
    dfs(3, 0, 1);
    printf("%d\n", ans);
    return 0;
}

