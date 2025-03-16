

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int x[n], y[m];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // Process the jobs in the order of their deadlines
    for (int i = 0; i < n; i++) {
        int max_index = 0;
        for (int j = 1; j < m; j++) {
            if (y[j] > y[max_index]) {
                max_index = j;
            }
        }
        y[max_index] += x[i];
    }

    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += y[i];
    }
    printf("%d\n", sum);

    return 0;
}
