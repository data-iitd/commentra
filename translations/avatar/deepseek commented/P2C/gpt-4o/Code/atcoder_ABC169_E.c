#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void resolve() {
    // Read the number of pairs
    int n;
    scanf("%d", &n);
    
    // Initialize arrays to store the lower and higher values of each pair
    int *low = (int *)malloc(n * sizeof(int));
    int *high = (int *)malloc(n * sizeof(int));
    
    // Loop to read each pair and store values in the arrays
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        low[i] = a;
        high[i] = b;
    }
    
    // Sort the arrays
    qsort(low, n, sizeof(int), compare);
    qsort(high, n, sizeof(int), compare);
    
    // Check if the number of pairs is odd or even
    if (n % 2) {
        // If odd, calculate the range between the middle elements
        printf("%d\n", high[(n + 1) / 2 - 1] - low[(n + 1) / 2 - 1] + 1);
    } else {
        // If even, calculate the average of the middle elements and print the range
        double hh = (high[n / 2 - 1] + high[n / 2]) / 2.0;
        double ll = (low[n / 2 - 1] + low[n / 2]) / 2.0;
        printf("%d\n", (int)((hh - ll) * 2) + 1);
    }
    
    // Free allocated memory
    free(low);
    free(high);
}

// Call the resolve function when the script is executed
int main() {
    resolve();
    return 0;
}

// <END-OF-CODE>
