#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void resolve() {
    // Read the number of intervals
    int n;
    scanf("%d", &n);
    
    // Initialize arrays to store the lower and upper bounds of the intervals
    int *low = (int *)malloc(n * sizeof(int));
    int *high = (int *)malloc(n * sizeof(int));
    
    // Read each interval and store the lower and upper bounds
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &low[i], &high[i]);
    }
    
    // Sort the lower and upper bounds
    qsort(low, n, sizeof(int), compare);
    qsort(high, n, sizeof(int), compare);
    
    // Check if the number of intervals is odd
    if (n % 2) {
        // For odd number of intervals, calculate the range of the median interval
        printf("%d\n", high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
    } else {
        // For even number of intervals, calculate the average of the two middle values
        double hh = (high[n / 2 - 1] + high[n / 2]) / 2.0;  // Average of the two middle high values
        double ll = (low[n / 2 - 1] + low[n / 2]) / 2.0;    // Average of the two middle low values
        // Calculate the range and print the result
        printf("%d\n", (int)((hh - ll) * 2) + 1);
    }
    
    // Free allocated memory
    free(low);
    free(high);
}

// Entry point of the program
int main() {
    resolve();
    return 0;
}

// <END-OF-CODE>
