#include <stdio.h>

int main() {
    int n, m;
    
    // Read the input from the user
    scanf("%d %d", &n, &m);
    
    // Calculate the quotient and remainder of n divided by m
    int q = n / m;
    int r = n % m;
    
    // Initialize the array with q repeated m times
    int a[m];
    for (int i = 0; i < m; i++) {
        a[i] = q;
    }
    
    // Increment the corresponding elements in the a array for the remaining elements
    for (int i = 0; i < r; i++) {
        a[i]++;
    }
    
    // Print each element of the a array separated by a space
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}

// <END-OF-CODE>
