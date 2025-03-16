#include <stdio.h>

int fun(int arr[], int q, int n);

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    scanf("%d", &arr[0]);
    
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        arr[i] = x + arr[i - 1];
    }
    
    int m;
    scanf("%d", &m);
    int q[m];
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &q[i]);
    }
    
    for (int k = 0; k < m; k++) {
        printf("%d\n", fun(arr, q[k], n) + 1);
    }
    
    return 0;
}

int fun(int arr[], int q, int n) {
    int res = 0;
    int i = 0, j = n - 1; // Adjusted j to n - 1 for correct indexing
    while (i <= j) {
        int md = i + (j - i) / 2;
        if (arr[md] == q) {
            return md;
        } else if (arr[md] > q) {
            res = md;
            j = md - 1;
        } else {
            i = md + 1;
        }
    }
    return res;
}

// <END-OF-CODE>
