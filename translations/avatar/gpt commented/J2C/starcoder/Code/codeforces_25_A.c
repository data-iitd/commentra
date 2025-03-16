#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, odd, even, odd_ind, even_ind;
    scanf("%d", &n);
    int array[n + 1];
    for (i = 1; i <= n; i++) {
        scanf("%d", &array[i]);
    }
    odd = even = odd_ind = even_ind = 0;
    for (i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) {
            even++;
            even_ind = i;
        } else {
            odd++;
            odd_ind = i;
        }
    }
    if (odd > even) {
        printf("%d\n", even_ind);
    } else {
        printf("%d\n", odd_ind);
    }
    return 0;
}
