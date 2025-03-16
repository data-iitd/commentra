#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<limits.h>
#include<stdbool.h>

// Function to check if it's possible to carry all books with n people and a given weight limit
bool check(int n, int wei, int *book) {
    int tmp = wei;
    n--;
    for (int i = 0; i < n; i++) {
        if (tmp < book[i]) {
            if (n > 0) {
                n--;
                tmp = wei;
                if (tmp < book[i])
                    return false;
            } else {
                return false;
            }
        }
        tmp -= book[i];
    }
    return true;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) == 2) {
        int *book = (int *) malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &book[i]);
        }

        // Binary search to find the maximum weight a person can carry
        int l = 0;
        int r = 1500000;
        int ans;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(m, mid, book)) {
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
