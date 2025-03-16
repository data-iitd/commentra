
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the scanner to split input by whitespace
    // (This step is not necessary in C, as it automatically handles whitespace)
    
    // Read two integers from input: n (number of elements) and k (some parameter)
    int n, k;
    scanf("%d %d", &n, &k);
    
    // Read 'n' integers into array 'a'
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Avoid unused variable error by assigning a value to the first element of 'a'
    a[0] = 0;

    // Initialize sum with the value of k and set ans to 1
    int sum = k;
    int ans = 1;
    
    // Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
    while (sum < n) {
        sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
        ans++; // Increment the answer counter
    }
    
    // Print the final answer
    printf("%d\n", ans);
    
    return 0;
}
