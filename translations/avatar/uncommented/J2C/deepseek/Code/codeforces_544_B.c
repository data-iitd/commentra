#include <stdio.h>
#include <stdlib.h>

void printIsland(int n, int count);

int main() {
    int n, count;
    scanf("%d %d", &n, &count);
    printIsland(n, count);
    return 0;
}

void printIsland(int n, int count) {
    int a = (n + 1) / 2;
    int b = n / 2;
    int max = a * a + b * b;
    if (count > max) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        char *row = (char *)malloc(n + 1);
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2 == 0 && count > 0) {
                row[j] = 'L';
                count--;
            } else {
                row[j] = 'S';
            }
        }
        row[n] = '\0';
        printf("%s\n", row);
        free(row);
    }
}
