
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0, c = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    for (int i = 0; i < n; i++) {
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++;
        }
    }
    printf("%d\n", c);
    // 