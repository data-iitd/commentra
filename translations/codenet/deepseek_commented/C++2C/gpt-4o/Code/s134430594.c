#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define int long long

// Structure to store the left, right, and value of a ban
typedef struct {
    int l;
    int r;
    int val;
} Ban;

// Namespace for sparse table operations
<<<<<<< HEAD
#define LIM 20 
=======
#define LIM 20
>>>>>>> 98c87cb78a (data updated)
#define N 200007

int mn[LIM][N];
int pw[N];

// Initialize the sparse table with the given array
void init(int *a, int n) {
    for (int i = 0; i < n; i++) {
<<<<<<< HEAD
        mn[0][i] = a[i]; 
=======
        mn[0][i] = a[i];
>>>>>>> 98c87cb78a (data updated)
    }
    for (int i = 0; i + 1 < LIM; i++) {
        for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
            mn[i + 1][j] = (mn[i][j] > mn[i][j + (1 << i)]) ? mn[i][j] : mn[i][j + (1 << i)];
        }
    }
    pw[1] = 0;
    for (int i = 2; i < N; i++) {
        pw[i] = pw[i / 2] + 1;
    }
<<<<<<< HEAD
} 
=======
}
>>>>>>> 98c87cb78a (data updated)

// Query the sparse table for the minimum value in the range [l, r)
int get(int l, int r) {
    r++;
    int p = pw[r - l];
    return (mn[p][l] < mn[p][r - (1 << p)]) ? mn[p][l] : mn[p][r - (1 << p)];
}

// Main function to execute the program
int main() {
    int n;
    scanf("%lld", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    int *dl = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (a[i] > i) {
            printf("-1\n");
            free(a);
            free(dl);
            return 0;
        }
        dl[i] = i - a[i];
    }
<<<<<<< HEAD
    int ans = 0;
    Ban *bans = (Ban *)malloc(n * sizeof(Ban));
    int ban_count = 0;
=======
    
    int ans = 0;
    Ban *bans = (Ban *)malloc(n * sizeof(Ban));
    int ban_count = 0;

>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n; i++) {
        int r = i;
        while (r + 1 < n && a[r] + 1 == a[r + 1]) {
            r++;
        }
        ans += a[r];
        i = r;
        bans[ban_count++] = (Ban){r - a[r], r, r - a[r]};
    }
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
    init(dl, n);
    for (int i = 0; i < ban_count; i++) {
        if (get(bans[i].l, bans[i].r) > bans[i].val) {
            printf("-1\n");
            free(a);
            free(dl);
            free(bans);
            return 0;
        }
    }
<<<<<<< HEAD
=======
    
>>>>>>> 98c87cb78a (data updated)
    printf("%lld\n", ans);
    
    free(a);
    free(dl);
    free(bans);
    return 0;
}

// <END-OF-CODE>
