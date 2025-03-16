#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF 1 << 29
#define LL long long int
#define MOD 1000000007

int main() {
    // Optimize input/output operations
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    // Read the number of elements and the constant c
    LL n, c;
    scanf("%lld %lld", &n, &c);

    // Initialize arrays to store positions and velocities
    LL x[n+1], v[n+1];

    // Read the positions and velocities of the elements
    for(int i = 1; i < n+1; i++){
        scanf("%lld %lld", &x[i], &v[i]);
    }

    // Initialize arrays to store cumulative velocities from the left
    LL lefttotal[n+1], maxlefttotal[n+1];
    memset(lefttotal, 0, sizeof(lefttotal));
    memset(maxlefttotal, 0, sizeof(maxlefttotal));
    
    // Calculate cumulative velocities from the left
    for(int i = 1; i < n+1; i++){
        lefttotal[i] = lefttotal[i-1] + v[i];
    }

    // Calculate the maximum value of lefttotal adjusted by position
    for(int i = 1; i < n+1; i++){
        maxlefttotal[i] = lefttotal[i] - x[i] > maxlefttotal[i-1] ? lefttotal[i] - x[i] : maxlefttotal[i-1];
    }

    // Initialize arrays to store cumulative velocities from the right
    LL righttotal[n+1], maxrighttotal[n+1];
    memset(righttotal, 0, sizeof(righttotal));
    memset(maxrighttotal, 0, sizeof(maxrighttotal));
    
    // Calculate cumulative velocities from the right
    for(int i = 1; i < n+1; i++){
        righttotal[i] = righttotal[i-1] + v[n-i+1];
    }
    
    // Calculate the maximum value of righttotal adjusted by position
    for(int i = 1; i < n+1; i++){
        maxrighttotal[i] = righttotal[i] - (c - x[n+1-i]) > maxrighttotal[i-1] ? righttotal[i] - (c - x[n+1-i]) : maxrighttotal[i-1];
    }

    // Initialize the answer variable to store the maximum result
    LL ans = 0;

    // Evaluate the maximum possible value based on different scenarios
    for(int i = 1; i < n+1; i++){
        ans = ans > lefttotal[i] - x[i] ? ans : lefttotal[i] - x[i]; // Scenario 1
        ans = ans > lefttotal[i] - 2 * x[i] + maxrighttotal[n-i] ? ans : lefttotal[i] - 2 * x[i] + maxrighttotal[n-i]; // Scenario 2
        ans = ans > righttotal[i] - (c - x[n+1-i]) ? ans : righttotal[i] - (c - x[n+1-i]); // Scenario 3
        ans = ans > righttotal[i] - 2 * (c - x[n+1-i]) + maxlefttotal[n-i] ? ans : righttotal[i] - 2 * (c - x[n+1-i]) + maxlefttotal[n-i]; // Scenario 4
    }

    // Output the final result
    printf("%lld\n", ans);
    
    return 0;
}
