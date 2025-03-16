#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int ans = arr[0] + 1;
    for (int i = 1; i < n; i++) {
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }
    
    printf("%d\n", ans);
    
    free(arr);
    return 0;
}

// <END-OF-CODE>
