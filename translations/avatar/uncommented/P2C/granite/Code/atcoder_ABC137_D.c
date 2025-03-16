
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int x[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i][0], &x[i][1]);
    }

    // Sort x by day in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (x[j][0] > x[j + 1][0]) {
                int temp_day = x[j][0];
                int temp_salary = x[j][1];
                x[j][0] = x[j + 1][0];
                x[j][1] = x[j + 1][1];
                x[j + 1][0] = temp_day;
                x[j + 1][1] = temp_salary;
            }
        }
    }

    int y[m];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (m - j >= -x[i][0]) {
            y[j] = x[i][1];
            j++;
        } else {
            y[j - 1] = x[i][1];
        }
    }

    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += y[i];
    }

    printf("%d\n", sum);

    return 0;
}
