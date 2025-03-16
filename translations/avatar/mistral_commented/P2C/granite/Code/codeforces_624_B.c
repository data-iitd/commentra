
#include <stdio.h>

int main() {
    // Read an integer n from the standard input
    int n;
    scanf("%d", &n);

    // Create an array a of size n by reading n integers from the standard input
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize two variables, pre and ans, to INT_MAX and 0, respectively
    int pre = INT_MAX;
    int ans = 0;

    // Sort the array a in descending order using the qsort() function
    qsort(a, n, sizeof(int), cmpfunc);

    // Iterate through the array a using a for loop
    for (int j = 0; j < n; j++) {
        // Calculate the maximum of 0 and the minimum of pre - 1 and a[j]. This value is added to ans.
        ans += fmax(0, fmin(pre - 1, a[j]));

        // Update the value of pre to be the minimum of pre - 1 and a[j].
        pre = fmin(pre - 1, a[j]);
    }

    // After the loop, print the value of ans.
    printf("%d\n", ans);

    return 0;
}

int cmpfunc(const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

