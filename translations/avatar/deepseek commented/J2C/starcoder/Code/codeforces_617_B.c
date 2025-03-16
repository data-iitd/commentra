
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = 1;
    for (int i = 1; i < n; i++) {
        result *= arr[i] - arr[i - 1];
    }
    printf("%d", result);
    return 0;
}

