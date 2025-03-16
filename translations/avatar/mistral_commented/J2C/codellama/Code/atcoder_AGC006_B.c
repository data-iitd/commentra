
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x;
    printf("Enter two integers: ");
    scanf("%d %d", &n, &x);
    int max = n * 2 - 1;
    if (x == 1 || x == max) {
        printf("No");
        return 0;
    }
    printf("Yes\n");
    char sep = '\n';
    for (int i = x + n - 1; i < x + n + max - 1; i++) {
        printf("%d%c", (i % max + 1), sep);
    }
    return 0;
}

