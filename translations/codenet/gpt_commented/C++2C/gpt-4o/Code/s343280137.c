#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF (1 << 29)
#define LL long long int
#define MOD 1000000007

int main() {
    // Optimize input/output operations
<<<<<<< HEAD
    // Note: In C, we don't have cin/cout, so we use printf/scanf
=======
    // No specific optimization in C like C++, but we can use scanf/printf
>>>>>>> 98c87cb78a (data updated)

    // Read the number of elements and the constant c
    LL n, c;
    scanf("%lld %lld", &n, &c);

    // Initialize arrays to store positions and velocities
    LL *x = (LL *)malloc((n + 1) * sizeof(LL));
    LL *v = (LL *)malloc((n + 1) * sizeof(LL));

    // Read the positions and velocities of the elements
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &v[i]);
    }

    // Initialize arrays to store cumulative velocities from the left
    LL *lefttotal = (LL *)malloc((n + 1) * sizeof(LL));
    LL *maxlefttotal = (LL *)malloc((n + 1) * sizeof(LL));
    
    // Calculate cumulative velocities from the left
    lefttotal[0] = 0;
    for (int i = 1; i <= n; i++) {
        lefttotal[i] = lefttotal[i - 1] + v[i];
    }

    // Calculate the maximum value of lefttotal adjusted by position
    maxlefttotal[0] = 0;
    for (int i = 1; i <= n; i++) {
        maxlefttotal[i] = (maxlefttotal[i - 1] > (lefttotal[i] - x[i])) ? maxlefttotal[i - 1] : (lefttotal[i] - x[i]);
    }

    // Initialize arrays to store cumulative velocities from the right
    LL *righttotal = (LL *)malloc((n + 1) * sizeof(LL));
    LL *maxrighttotal = (LL *)malloc((n + 1) * sizeof(LL));
    
    // Calculate cumulative velocities from the right
    righttotal[0] = 0;
    for (int i = 1; i <= n; i++) {
        righttotal[i] = righttotal[i - 1] + v[n - i + 1];
    }
    
    // Calculate the maximum value of righttotal adjusted by position
    maxrighttotal[0] = 0;
    for (int i = 1; i <= n; i++) {
        maxrighttotal[i] = (maxrighttotal[i - 1] > (righttotal[i] - (c - x[n + 1 - i]))) ? maxrighttotal[i - 1] : (righttotal[i] - (c - x[n + 1 - i]));
    }

    // Initialize the answer variable to store the maximum result
    LL ans = 0;

    // Evaluate the maximum possible value based on different scenarios
    for (int i = 1; i <= n; i++) {
        ans = (ans > (lefttotal[i] - x[i])) ? ans : (lefttotal[i] - x[i]); // Scenario 1
        ans = (ans > (lefttotal[i] - 2 * x[i] + maxrighttotal[n - i])) ? ans : (lefttotal[i] - 2 * x[i] + maxrighttotal[n - i]); // Scenario 2
        ans = (ans > (righttotal[i] - (c - x[n + 1 - i]))) ? ans : (righttotal[i] - (c - x[n + 1 - i])); // Scenario 3
        ans = (ans > (righttotal[i] - 2 * (c - x[n + 1 - i]) + maxlefttotal[n - i])) ? ans : (righttotal[i] - 2 * (c - x[n + 1 - i]) + maxlefttotal[n - i]); // Scenario 4
    }

    // Output the final result
    printf("%lld\n", ans);

    // Free allocated memory
    free(x);
    free(v);
    free(lefttotal);
    free(maxlefttotal);
    free(righttotal);
    free(maxrighttotal);
    
    return 0;
}

// <END-OF-CODE>
