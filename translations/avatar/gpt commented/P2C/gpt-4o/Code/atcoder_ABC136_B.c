#include <stdio.h>
#include <math.h>

int main() {
    // Read an integer input from the user
    int N;
    scanf("%d", &N);
    
    // Initialize the variable to keep track of the power of 10
    int i = 1;
    
    // Initialize the answer variable to accumulate the result
    long long ans = 0;
    
    // Loop to calculate the contribution of each range of numbers defined by powers of 10
    while (pow(10, i) <= N) {
        // Add the count of numbers in the current range (10^(i-1) to 10^i)
        ans += (pow(10, i) - pow(10, i - 1));
        
        // Increment i by 2 to move to the next range (skipping even powers)
        i += 2;
    }
    
    // Add the count of numbers from the last valid power of 10 to N
    ans += (N - pow(10, i - 1) + 1 > 0) ? (N - pow(10, i - 1) + 1) : 0;
    
    // Print the final result
    printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>
