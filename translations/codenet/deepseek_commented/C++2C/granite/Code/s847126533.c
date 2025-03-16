
#include<stdio.h>
#include<stdlib.h>

// Function to check if it's possible to carry all books with n people and a given weight limit
int check(int n, int wei, int *book, int size) {
    int tmp = wei;
    n--;
    for (int i = 0; i < size; i++) {
        if (tmp < book[i]) {
            if (n > 0) {
                n--;
                tmp = wei;
                if (tmp < book[i])
                    return 0;
            } else {
                return 0;
            }
        }
        tmp -= book[i];
    }
    return 1;
}

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n), m) {
        int *book = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &book[i]);
        }

        // Binary search to find the maximum weight a person can carry
        int l = 0;
        int r = 1500000;
        int ans;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(m, mid, book, n)) {
                ans = mid;
                r = mid; // Adjust the right boundary
            } else {
                l = mid; // Adjust the left boundary
            }
        }
        printf("%d\n", ans);
        free(book);
    }
}
