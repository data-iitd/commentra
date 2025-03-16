
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
    int n = 0;
    scanf("%d", &n);
    char c;
    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);
        switch (c) {
            case 'M':
                a[0]++;
                break;
            case 'A':
                a[1]++;
                break;
            case 'R':
                a[2]++;
                break;
            case 'C':
                a[3]++;
                break;
            case 'H':
                a[4]++;
                break;
        }
    }
    dfs(3, 0, 1);
    printf("%d\n", ans);
    return 0;
}
