#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Structure to store the left, right, and value of a ban
typedef struct {
    int l;
    int r;
    int val;
} Ban;

// Namespace for sparse table operations
namespace Sp {
    const int LIM = 20; 
    const int N = 2e5 + 7;

    int mn[LIM][N];
    int pw[N];

    // Initialize the sparse table with the given array
    void init(int *a, int n) {
        for (int i = 0; i < n; i++) {
            mn[0][i] = a[i]; 
        }
        for (int i = 0; i + 1 < LIM; i++) {
            for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                mn[i + 1][j] = a[j] > a[j + (1 << i)] ? a[j] : a[j + (1 << i)];
            }
        }
        pw[1] = 0;
        for (int i = 2; i < N; i++) {
            pw[i] = pw[i / 2] + 1;
        }
    } 

    // Query the sparse table for the minimum value in the range [l, r)
    int get(int l, int r) {
        r++;
        int p = pw[r - l];
        return mn[p][l] < mn[p][r - (1 << p)] ? mn[p][l] : mn[p][r - (1 << p)];
    }
}

// Main function to execute the program
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int dl[n];
    for (int i = 0; i < n; i++) {
        if (a[i] > i) {
            printf("-1\n");
            return 0;
        }
        dl[i] = i - a[i];
    }
    int ans = 0;
    Ban bans[n];
    int ban_count = 0;
    for (int i = 0; i < n; i++) {
        int r = i;
        while (r + 1 < n && a[r] + 1 == a[r + 1]) {
            r++;
        }
        ans += a[r];
        i = r;
        bans[ban_count++] = (Ban){r - a[r], r, r - a[r]};
    }
    Sp::init(dl, n);
    for (int i = 0; i < ban_count; i++) {
        if (Sp::get(bans[i].l, bans[i].r) > bans[i].val) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", ans);
}
