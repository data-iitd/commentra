#include <stdio.h>

void print(int x, int n) {
    int max = n * 2 - 1;
    
    if (x == 1 || x == max) {
        printf("No\n");
        return;
    }
    
    printf("Yes\n");
    
    char sep = '\n';
    
    char ans[1000];
    int index = 0;
    
    for (int i = x + n - 1; i < x + n + max; i++) {
        int adjusted = (i % max) + 1;
        index += sprintf(ans + index, "%d%c", adjusted, sep);
    }
    
    printf("%s", ans);
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    print(x, n);
    return 0;
}

