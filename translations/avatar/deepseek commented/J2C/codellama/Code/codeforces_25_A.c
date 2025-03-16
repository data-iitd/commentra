#include <stdio.h>

int main() {
    int n, array[100000], i, odd = 0, even = 0, odd_ind = 0, even_ind = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            even++;
            even_ind = i;
        } else {
            odd++;
            odd_ind = i;
        }
    }

    if (odd > even) {
        printf("%d", even_ind);
    } else {
        printf("%d", odd_ind);
    }

    return 0;
}

