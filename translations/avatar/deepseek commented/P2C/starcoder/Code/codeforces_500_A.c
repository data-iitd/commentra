
#include <stdio.h>

int main() {
    int n, t, current_cell, i;
    scanf("%d %d", &n, &t);
    int s[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    current_cell = 0;
    while (current_cell <= t) {
        current_cell += s[current_cell - 1];
        if (current_cell == t) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}

