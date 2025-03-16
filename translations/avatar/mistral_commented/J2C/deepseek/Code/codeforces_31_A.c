#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, f = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int k = 0; k < n; k++) {
        int t = a[k];
        for (int i = 0; i < n; i++) {
            if (i != k) {
                for (int j = 0; j < n - 1; j++) {
                    if (i != j && t == (a[i] + a[j])) {
                        f = 1;
                        printf("Indices: %d %d %d\n", k + 1, i + 1, j + 1);
                        break;
                    }
                }
                if (f == 1) {
                    break;
                }
            }
        }
        if (f == 1) {
            break;
        }
    }

    if (f == 0) {
        printf("-1\n");
    }

    return 0;
}
