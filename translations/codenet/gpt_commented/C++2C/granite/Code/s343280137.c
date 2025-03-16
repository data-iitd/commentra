
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
    // Define constants for infinity and long long integer type
    #define INF 1 << 29
    #define LL long long int

    // Define a constant for modulo operation
    LL const MOD = 1000000007;

    // Read the number of elements and the constant c
    LL n, c;
    scanf("%lld %lld", &n, &c);

    // Initialize arrays to store positions and velocities
    LL x[n+1], v[n+1];
    for(int i = 1; i < n+1; i++){
        scanf("%lld %lld", &x[i], &v[i]);
    }

    // Initialize arrays to store cumulative velocities from the left
    LL lefttotal[n+1], maxlefttotal[n+1];
    lefttotal[0] = 0;
    maxlefttotal[0] = 0;
    for(int i = 1; i < n+1; i++){
        lefttotal[i] = lefttotal[i-1] + v[i];
        maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i] - x[i]);
    }

    // Initialize arrays to store cumulative velocities from the right
    LL righttotal[n+1], maxrighttotal[n+1];
    righttotal[0] = 0;
    maxrighttotal[0] = 0;
    for(int i = 1; i < n+1; i++){
        righttotal[i] = righttotal[i-1] + v[n-i+1];
        maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i] - (c - x[n+1-i]));
    }

    // Initialize the answer variable to store the maximum result
    LL ans = 0;

    // Evaluate the maximum possible value based on different scenarios
    for(int i = 1; i < n+1; i++){
        ans = max(ans, lefttotal[i] - x[i]); // Scenario 1
        ans = max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[n-i]); // Scenario 2
        ans = max(ans, righttotal[i] - (c - x[n+1-i])); // Scenario 3
        ans = max(ans, righttotal[i] - 2 * (c - x[n+1-i]) + maxlefttotal[n-i]); // Scenario 4
    }

    // Output the final result
    printf("%lld\n", ans);
    
    return 0;
}
