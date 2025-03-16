
#include <stdio.h>

// Function to check if 'k' is positive after checking all elements in 'lis' with mid as divisor
int check(int lis[], int n, int k, int mid) {
    // Iterate through each element in the list 'lis'
    for (int i = 0; i < n; i++) {
        // If the element 'lis[i]' is divisible by'mid', increment 'k'
        if (lis[i] % mid == 0) {
            k += 1;
        }
        // Subtract the quotient of 'lis[i]' and'mid' from 'k'
        k -= (lis[i] / mid);
    }
    // Return 1 if 'k' is still positive after the loop, else 0
    return k >= 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int lis[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lis[i]);
    }
    int a = 1, b = *max_element(lis, lis + n);
    int ans = b;
    while (a <= b) {
        int mid = (a + b) / 2;
        if (check(lis, n, k, mid)) {
            ans = mid;
            b = mid - 1;
        } else {
            a = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}

