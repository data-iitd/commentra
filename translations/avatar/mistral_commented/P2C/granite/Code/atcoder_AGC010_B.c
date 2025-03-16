
#include <stdio.h>

int main() {
    int n, a[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    // Check if the sum of the elements in the array is divisible by the formula
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    if (sum % (n * (n + 1) / 2)) {
        printf("NO\n");
        return 0;
    }

    // Calculate the average of the elements in the array
    double k = (double)sum / (n * (n + 1) / 2);

    // Add the first element to the end of the array for simplification
    int temp = a[0];
    for (int i = 0; i < n - 1; i++) a[i] = a[i + 1];
    a[n - 1] = temp;

    // Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if ((k - a[i] + a[i + 1]) % n || (k - a[i] + a[i + 1]) / n < 0) {
            flag = 1;
            break;
        }
    }
    if (flag) printf("NO\n");
    else printf("YES\n");

    return 0;
}
