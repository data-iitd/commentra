#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int i = 1, j = n * n;
    while (i < j) {
        printf("%d %d\n", i, j);
        i++;
        j--;
    }
    return 0;
}
