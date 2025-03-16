#include <stdio.h> 
#include <stdlib.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int n, i, j, max = 0; 
    int *beacon, *dp; 
    scanf("%d", &n); 
    beacon = (int *)malloc(n * sizeof(int)); 
    dp = (int *)malloc(n * sizeof(int)); 
    for (i = 0; i < n; i++) { 
        scanf("%d", &beacon[i]); 
    } 
    dp[0] = beacon[0] != 0; 
    for (i = 1; i < n; i++) { 
        if (beacon[i] != 0 && beacon[i] < i) { 
            dp[i] = dp[i - beacon[i] - 1] + 1; 
        } 
        else if (beacon[i] != 0) { 
            dp[i] = 1; 
        } 
        else { 
            dp[i] = dp[i - 1]; 
        } 
        max = max > dp[i] ? max : dp[i]; 
    } 
    printf("%d", n - max); 
    return 0; 
} 
