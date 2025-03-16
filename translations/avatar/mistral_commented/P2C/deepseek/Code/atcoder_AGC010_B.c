#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Check if the sum of the elements in the list is divisible by the formula
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    if (sum % (n * (n + 1) / 2)) {
        printf("NO\n");
        return 0;
    }

    // Calculate the average of the elements in the list
    double k = (double)sum / (n * (n + 1) / 2);

    // Add the first element to the end of the list for simplification
    int a_new[n + 1];
    for (i = 0; i < n; i++) {
        a_new[i] = a[i];
    }
    a_new[n] = a[0];

    // Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
    int valid = 1;
    for (i = 1; i <= n; i++) {
        if ((int)(k - i + a_new[i]) % n != 0) {
            valid = 0;
            break;
        }
        if ((k - i + a_new[i]) / n < 0) {
            valid = 0;
            break;
        }
    }

    if (!valid) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }

    return 0;
}
