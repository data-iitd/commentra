
#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int lista[a];
    for (int i = 0; i < a; i++) {
        scanf("%d", &lista[i]);
    }

    int listb[b];
    for (int i = 0; i < b; i++) {
        scanf("%d", &listb[i]);
    }

    for (int k = 0; k < n; k++) {
        if (k + 1 == lista[0]) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    }

    return 0;
}
