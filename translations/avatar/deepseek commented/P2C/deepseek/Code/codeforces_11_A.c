#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int x[n];
    int m = 0;
    int q = 0;

    char input[100];
    scanf(" %[^\n]", input);
    char *token = strtok(input, " ");
    int index = 0;
    while (token != NULL) {
        x[index++] = atoi(token);
        token = strtok(NULL, " ");
    }

    for (int a = 0; a < n - 1; a++) {
        if (x[a] >= x[a + 1]) {
            q = (x[a] - x[a + 1]) / d + 1;
            m = m + q;
            x[a + 1] = x[a + 1] + q * d;
        }
    }

    printf("%d\n", m);
    return 0;
}
