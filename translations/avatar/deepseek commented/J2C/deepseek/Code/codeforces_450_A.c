#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *elements = (int *)malloc(n * sizeof(int));
    int *indices = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
        indices[i] = i + 1;
    }

    int ans = 0;

    while (n > 0) {
        if (elements[0] <= m) {
            ans = indices[0];
            for (int i = 0; i < n - 1; i++) {
                elements[i] = elements[i + 1];
                indices[i] = indices[i + 1];
            }
            n--;
        } else {
            int x = elements[0];
            elements[0] = x - m;
            for (int i = 0; i < n - 1; i++) {
                elements[i] = elements[i + 1];
                indices[i] = indices[i + 1];
            }
            indices[n - 1] = indices[n - 2];
        }
    }

    printf("%d\n", ans);
    free(elements);
    free(indices);

    return 0;
}

