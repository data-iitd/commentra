#include <stdio.h>

#define MAX_SIZE 100002

// Function to find the maximum of two integers.
int max(int x, int y) {
    return (x > y) ? x : y;
}

// Solution function takes an integer n and an array a as input.
int solution(int n, int a[]) {
    int memo[MAX_SIZE] = {0}; // Initialize memoization array with zeros.
    
    for (int i = 0; i < n; i++) {
        memo[a[i]]++;
        memo[a[i] + 1]++;
        memo[a[i] + 2]++;
    }
    
    int out = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (memo[i] > 0) {
            out = max(out, memo[i]);
        }
    }
    
    return out;
}

// Main function reads the input values, calls the solution function, and prints the result.
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("%d\n", solution(n, a));
    return 0;
}

// <END-OF-CODE>
