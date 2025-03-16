#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *a = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Check if the sum of the elements in the list is divisible by the formula
    int sum_a = 0;
    for (int i = 0; i < n; i++) {
        sum_a += a[i];
    }

    if (sum_a % (n * (n + 1) / 2) != 0) {
        printf("NO\n");
        free(a);
        return 0;
    }

    // Calculate the average of the elements in the list
    double k = (double)sum_a / (n * (n + 1) / 2);

    // Add the first element to the end of the list for simplification
    a[n] = a[0];

    // Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
    int valid = 1;
    for (int i = 1; i <= n; i++) {
        if ((int)((k - a[i] + a[i - 1]) % n) != 0) {
            valid = 0;
            break;
        }
    }

    if (!valid) {
        printf("NO\n");
        free(a);
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if ((k - a[i] + a[i - 1]) / n < 0) {
            count++;
        }
    }

    if (count != n) {
        printf("NO\n");
        free(a);
        return 0;
    }

    // If all checks pass, print YES
    printf("YES\n");
    free(a);
    return 0;
}

// <END-OF-CODE>
