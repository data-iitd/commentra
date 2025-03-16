
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *l = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    int high = 1;
    int tower = n;
    int maximum = 1;
    for (int i = 1; i < n; i++) {
        if (l[i] == l[i - 1]) {
            tower--;
            high++;
        } else {
            if (high > maximum) {
                maximum = high;
            }
            high = 1;
        }
    }
    if (high > maximum) {
        maximum = high;
    }
    printf("%d %d", maximum, tower);
    return 0;
}

