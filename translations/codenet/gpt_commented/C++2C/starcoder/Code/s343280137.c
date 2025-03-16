#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

// Define constants for infinity and long long integer type
#define INF 1 << 29
#define LL long long int

// Define a constant for modulo operation
LL const MOD = 1000000007;

int main(){
    // Optimize input/output operations
    // using "freopen" may help
    // to optimize input/output operations
    // for faster I/O
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Read the number of elements and the constant c
    LL n, c;
    scanf("%lld %lld", &n, &c);

    // Initialize vectors to store positions and velocities
    LL *x = (LL *)malloc(sizeof(LL) * (n+1));
    LL *v = (LL *)malloc(sizeof(LL) * (n+1));

    // Read the positions and velocities of the elements
    for(int i = 1; i < n+1; i++){
        scanf("%lld %lld", &x[i], &v[i]);
    }

    // Initialize vectors to store cumulative velocities from the left
    LL *lefttotal = (LL *)malloc(sizeof(LL) * (n+1));
    LL *maxlefttotal = (LL *)malloc(sizeof(LL) * (n+1));
    
    // Calculate cumulative velocities from the left
    for(int i = 1; i < n+1; i++){
        lefttotal[i] = lefttotal[i-1] + v[i];
    }

    // Calculate the maximum value of lefttotal adjusted by position
    for(int i = 1; i < n+1; i++){
        maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i] - x[i]);
    }

    // Initialize vectors to store cumulative velocities from the right
    LL *righttotal = (LL *)malloc(sizeof(LL) * (n+1));
    LL *maxrighttotal = (LL *)malloc(sizeof(LL) * (n+1));
    
    // Calculate cumulative velocities from the right
    for(int i = 1; i < n+1; i++){
        righttotal[i] = righttotal[i-1] + v[n-i+1];
    }
    
    // Calculate the maximum value of righttotal adjusted by position
    for(int i = 1; i < n+1; i++){
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

