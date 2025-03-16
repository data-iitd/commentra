
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    print(x, n);
    return 0;
}

void print(int x, int n) {
    int max = n * 2 - 1;
    if (x == 1 || x == max) {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    char sep[2] = "\n";
    char ans[100000];
    int i;
    for (i = x + n - 1; i < x + n + max - 1; i++) {
        ans[i - x + n - 1] = (i % max + 1) + sep[0];
    }
    printf("%s", ans);
}

