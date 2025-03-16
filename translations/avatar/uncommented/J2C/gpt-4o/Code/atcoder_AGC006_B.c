#include <stdio.h>

void print(int x, int n) {
    int max = n * 2 - 1;
    if (x == 1 || x == max) {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    
    for (int i = x + n - 1; i < x + n + max - 1; i++) {
        printf("%d\n", (i % max) + 1);
    }
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    print(x, n);
    return 0;
}

// <END-OF-CODE>
