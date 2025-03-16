#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *values = (int *)malloc(n * sizeof(int));
    int *indices = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
        indices[i] = i + 1;
    }

    int ans = 0;

    while (n > 0) {
        if (values[0] <= m) {
            ans = indices[0];
            for (int i = 1; i < n; i++) {
                values[i - 1] = values[i];
                indices[i - 1] = indices[i];
            }
            n--;
        } else {
            values[0] -= m;
            for (int i = 1; i < n; i++) {
                values[i - 1] = values[i];
                indices[i - 1] = indices[i];
            }
            indices[n - 1] = indices[n];
        }
    }

    printf("%d\n", ans);

    free(values);
    free(indices);

    return 0;
}

