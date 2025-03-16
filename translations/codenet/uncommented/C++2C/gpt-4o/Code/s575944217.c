#include <stdio.h>

#define MAX_V 100001

int main() {
    int n;
    scanf("%d", &n);
    int ans[MAX_V] = {0}; // Initialize the array to zero

    for (int i = 0; i < n - 1; i++) {
        int a;
        scanf("%d", &a);
        a--; // Decrement to match 0-based index
        ans[a]++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}

// <END-OF-CODE>
