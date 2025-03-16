#include <stdio.h>

#define MOD 1000000007

int main() {
    // Variable to hold the number of test cases.
    int t;
    // Read the number of test cases.
    scanf("%d", &t);
    
    while (t-- > 0) {
        // Variables to hold n, a, and b.
        long n, a, b;
        // Read the values of n, a, and b.
        scanf("%ld %ld %ld", &n, &a, &b);
        
        // Check if n is less than a.
        if (n < a) {
            printf("No\n");
            continue;
        }
        
        // Check if a is equal to b.
        if (a == b) {
            if (n % a == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
            continue;
        }
        
        // Calculate x as b / (b - a).
        long x = b / (b - a);
        
        // Check if n is greater than x * a.
        if (n > x * a) {
            printf("Yes\n");
            continue;
        }
        
        // Perform binary search to find the minimum ans.
        long low = 1;
        long high = x + 1;
        long ans = 1;
        
        while (low <= high) {
            long mid = (low + high) / 2;
            if (mid * a < n) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        
        // Check if n lies between (ans - 1) * b and ans * a.
        if (n > (ans - 1) * b && n < ans * a) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    
    return 0;
}

// <END-OF-CODE>
