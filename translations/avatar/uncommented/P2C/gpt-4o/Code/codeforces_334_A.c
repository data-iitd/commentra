#include <stdio.h>

int main() {
    int n, i = 1, j;
    scanf("%d", &n);
    j = n * n;

    while (i < j) {
        printf("%d %d\n", i, j);
        i++;
        j--;
    }

    return 0;
}
// <END-OF-CODE>
