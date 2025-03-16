
#include <stdio.h>
#include <limits.h>

int main() {
    // Read the values of n and x
    int n, x;
    scanf("%d %d", &n, &x);
    
    // Read the list of integers a
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Initialize a 2D array b with INT_MAX values
    // b[j][i] will store the minimum value in the circular array from i to j
    int b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = INT_MAX;
        }
    }
    
    // Calculate the minimum value in a circular array for each starting position i and ending position j
    for (int i = 0; i < n; i++) {
        int m = a[i];  // Initialize m with the current element
        for (int j = 0; j < n; j++) {
            int k = i - j;  // Calculate the index in the circular array
            if (k < 0) {
                k += n;  // Adjust k if it is negative
            }
            m = (m < a[k])? m : a[k];  // Update m with the minimum value in the circular array
            b[j][i] = m;  // Store the minimum value in b
        }
    }
    
    // Find the minimum sum of each row in b plus x times the row index
    int m = INT_MAX;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += b[j][i];
        }
        sum += x * i;
        m = (m < sum)? m : sum;
    }
    
    // Print the minimum value found
    printf("%d\n", m);
    
    return 0;
}
