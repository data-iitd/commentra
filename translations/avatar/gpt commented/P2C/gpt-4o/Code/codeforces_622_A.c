#include <stdio.h>

int main() {
    // Taking input from the user
    int n;
    scanf("%d", &n);

    // Initializing left and right pointers for binary search
    int l = 1;
    int r = n;

    // Performing binary search to find the largest integer 'l'
    while (l < r) {
        // Calculating the midpoint of the current range
        int mid = l + (r - l) / 2;

        // Calculating the sum of the first 'mid' integers
        long long idxcnt = (long long)mid * (mid + 1) / 2;

        // If the sum is less than 'n', move the left pointer up
        if (idxcnt < n) {
            l = mid + 1;
        } else {
            // Otherwise, move the right pointer down
            r = mid;
        }
    }

    // Adjusting 'l' to get the largest valid integer
    l -= 1;

    // Calculating the sum of the first 'l' integers
    long long idxcnt = (long long)l * (l + 1) / 2;

    // Printing the difference between 'n' and the sum of the first 'l' integers
    printf("%lld\n", n - idxcnt);

    return 0;
}

// <END-OF-CODE>
