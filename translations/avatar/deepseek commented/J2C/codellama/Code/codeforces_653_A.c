
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                a[j] = a[n - 1];
                n--;
                j--;
            }
        }
    }
    for (int i = 0; i < n - 2; i++) {
        if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

