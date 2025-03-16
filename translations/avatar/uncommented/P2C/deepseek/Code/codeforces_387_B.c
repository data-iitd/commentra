#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int round_complexity[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &round_complexity[i]);
    }
    int george_complexity[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &george_complexity[i]);
    }
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (round_complexity[i] <= george_complexity[j]) {
            i++;
        }
        j++;
    }
    printf("%d\n", n - i);
    return 0;
}
