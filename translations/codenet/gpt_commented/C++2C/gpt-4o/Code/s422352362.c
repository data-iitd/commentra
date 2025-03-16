#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>
=======
>>>>>>> 98c87cb78a (data updated)
#include <math.h>

long long a[200005];
long long pre[200005];
long long last[200005];

int main() {
    int n;
    // Read the number of elements
    scanf("%d", &n);
    
    // Read the input values into the array 'a'
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    long long sumpre = 0, sumlast = 0;

    // Calculate prefix sums and store them in 'pre' array
    for(int i = 1; i < n; i++) {
<<<<<<< HEAD
        sumpre = sumpre + a[i];
=======
        sumpre += a[i];
>>>>>>> 98c87cb78a (data updated)
        pre[i] = sumpre;
        // Debugging output for prefix sums (commented out)
        // printf("%lld++\n", pre[i]);
    }

    // Calculate suffix sums and store them in 'last' array
    for(int i = n; i > 1; i--) {
<<<<<<< HEAD
        sumlast = sumlast + a[i];
=======
        sumlast += a[i];
>>>>>>> 98c87cb78a (data updated)
        last[i] = sumlast;
        // Debugging output for suffix sums (commented out)
        // printf("%lld+++\n", last[i]);
    }

    // Initialize 'd' to a large value to find the minimum difference
    long long d = (1ll << 60);

    // Calculate the minimum absolute difference between prefix and suffix sums
    for(int i = 1; i < n; i++) {
        // Debugging output for the difference calculation (commented out)
        // printf("%lld\n", pre[i] - last[i + 1]);
<<<<<<< HEAD
        d = fmin(d, llabs(pre[i] - last[i + 1]));
=======
        long long diff = llabs(pre[i] - last[i + 1]);
        if (diff < d) {
            d = diff;
        }
>>>>>>> 98c87cb78a (data updated)
    }

    // Output the minimum difference found
    printf("%lld\n", d);
    
    return 0;
}

// <END-OF-CODE>
