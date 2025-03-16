#include <stdio.h>

int n, ans = 0;

#define ARRAY_SIZE 101

int a[ARRAY_SIZE][ARRAY_SIZE];

void findAns(int i, int j, int sum) {
    if (i == 1 && j == n - 1 && sum + a[i][j] > ans) {
        ans = sum + a[i][j];
        return;
    }
    if (i == 0) {
        findAns(i + 1, j, sum + a[i][j]);
    }
    if (j + 1 < n) {
        findAns(i, j + 1, sum + a[i][j]);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    findAns(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
