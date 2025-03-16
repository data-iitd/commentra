#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *weights = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int count[200001] = {0};
    for (int i = 0; i < n; i++) {
        count[weights[i] + 100000]++;
    }

    long long c = 0;
    for (int i = 0; i <= 200000; i++) {
        if (i == 100000) {
            c += count[i] * (count[i] - 1);
        } else {
            if (count[200000 - i]) {
                c += count[i] * count[200000 - i];
            }
        }
    }
    printf("%lld\n", c / 2);

    free(weights);
    return 0;
}
