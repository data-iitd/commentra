#include <stdio.h>

int check(int lis[], int n, int k, int mid) {
    for (int i = 0; i < n; i++) {
        if (lis[i] % mid == 0) {
            k++;
        }
        k -= (lis[i] / mid);
    }
    return k >= 0;
}

int main() {
    int n, k;
    // Take input of 'n' and 'k'
    scanf("%d %d", &n, &k);

    int lis[n];
    // Take input of 'n' number of elements in the list 'lis'
    for (int i = 0; i < n; i++) {
        scanf("%d", &lis[i]);
    }

    int a = 1, b = 0;
    // Initialize 'b' with the maximum value in 'lis'
    for (int i = 0; i < n; i++) {
        if (lis[i] > b) {
            b = lis[i];
        }
    }

    int ans = b;

    // Binary search algorithm to find the answer
    while (a <= b) {
        int mid = (a + b) / 2;
        if (check(lis, n, k, mid)) {
            ans = mid;
            b = mid - 1;
        } else {
            a = mid + 1;
        }
    }

    // Print the answer
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
