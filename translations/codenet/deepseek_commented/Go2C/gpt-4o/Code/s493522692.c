#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Utility Functions

// Returns the minimum of two integers
int minInt(int a, int b) {
    return (a < b) ? a : b;
}

// Main Function
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int tmp = minInt(N, M / 2);
    int ans = 0;
    ans += tmp;
    N -= tmp;
    M -= tmp * 2;

    printf("%d\n", ans + M / 4);
    
    return 0;
}

// <END-OF-CODE>
