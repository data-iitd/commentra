#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    int *count = (int *)calloc(200001, sizeof(int)); // To handle values from -100000 to 100000

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count[arr[i] + 100000]++; // Shift index to handle negative values
    }

    long long c = 0;
    for (int i = -100000; i <= 100000; i++) {
        if (count[i + 100000] > 0) {
            if (i == 0) {
                c += count[i + 100000] * (count[i + 100000] - 1);
            } else if (count[-i + 100000] > 0) {
                c += count[i + 100000] * count[-i + 100000];
            }
        }
    }

    printf("%lld\n", c / 2);
    
    free(arr);
    free(count);
    return 0;
}

// <END-OF-CODE>
