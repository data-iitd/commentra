#include <stdio.h>
#include <stdlib.h>

int check(int n, int wei, int *book, int size) {
    int tmp = wei;
    n--;
    for (int i = 0; i < size; i++) {
        if (tmp < book[i]) {
            if (n > 0) {
                n--;
                tmp = wei;
                if (tmp < book[i])
                    return 0; // false
            } else {
                return 0; // false
            }
        }
        tmp -= book[i];
    }
    return 1; // true
}

int main() {
    int m, n;
<<<<<<< HEAD
    while (scanf("%d %d", &m, &n), m) {
=======
    while (scanf("%d %d", &m, &n) == 2 && m) {
>>>>>>> 98c87cb78a (data updated)
        int *book = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &book[i]);
        }

        int l = 0;
        int r = 1500000;
        int ans = 0;
        while (l < r) {
            if (check(m, (l + r) / 2, book, n)) {
                ans = (l + r) / 2;
                if (r == (l + r) / 2)
                    break;
                r = (l + r) / 2;
            } else {
                if (l == (l + r) / 2)
                    break;
                l = (l + r) / 2;
            }
        }
        printf("%d\n", ans);
        free(book);
    }
    return 0;
}

// <END-OF-CODE>
