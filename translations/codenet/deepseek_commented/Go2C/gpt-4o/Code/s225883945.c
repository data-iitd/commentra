#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
<<<<<<< HEAD
    // Read the array a, but we don't actually need to use it.
=======
    // Read the array a, but we don't actually need to use it based on the original logic.
>>>>>>> 98c87cb78a (data updated)
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Set the first element of `a` to 0 to avoid unused variable warning.
    a[0] = 0;

    int sum = k;
    int ans = 1;

    // Loop to increment `sum` and `ans` until `sum` is less than `n`.
    while (sum < n) {
        sum = sum - 1 + k;
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
