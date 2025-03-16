#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    int *s = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    int current_cell = 0;

    while (current_cell < t) {
        current_cell += s[current_cell] - 1;

        if (current_cell == t - 1) {
            printf("YES\n");
            free(s);
            return 0;
        }
    }

    printf("NO\n");
    free(s);
    return 0;
}
