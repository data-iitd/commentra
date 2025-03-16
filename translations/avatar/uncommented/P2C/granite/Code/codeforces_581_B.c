
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int ans[n];
    int mx = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        ans[i] = mx - arr[i] + 1;
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}

