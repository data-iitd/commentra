#include <stdio.h>

// Function to calculate the sum of first 'n' natural numbers
int sum_of_first_n(int n) {
    return (1 + n) * n / 2;
}

// Function to solve the problem
int solve(int n) {
    int s = sum_of_first_n(n);
    int t = 1;
    
    while (t <= n) {
        s -= 2 * t;
        t *= 2;
    }
    
    return s;
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    
    return 0;
}
