
#include <stdio.h>
#include <stdlib.h>

void resolve() {
    // Read the number of pairs
    int n;
    scanf("%d", &n);
    
    // Initialize arrays to store the lower and higher values of each pair
    int low[n], high[n];
    
    // Loop to read each pair and store values in the arrays
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &low[i], &high[i]);
    }
    
    // Sort the arrays
    qsort(low, n, sizeof(int));
    qsort(high, n, sizeof(int));
    
    // Check if the number of pairs is odd or even
    if (n % 2) {
        // If odd, calculate the range between the middle elements
        printf("%d\n", high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
    } else {
        // If even, calculate the average of the middle elements and print the range
        int hh = (high[n / 2 - 1] + high[n / 2]) / 2;
        int ll = (low[n / 2 - 1] + low[n / 2]) / 2;
        printf("%d\n", (hh - ll) * 2 + 1);
    }
}

int main() {
    resolve();
    return 0;
}

