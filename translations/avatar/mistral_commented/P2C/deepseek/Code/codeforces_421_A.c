#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int lista[a], listb[b];
    for (int i = 0; i < a; i++) {
        scanf("%d", &lista[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &listb[i]);
    }

    for (int k = 0; k < n; k++) {
        int is_in_lista = 0;
        for (int j = 0; j < a; j++) {
            if (k + 1 == lista[j]) {
                is_in_lista = 1;
                break;
            }
        }
        if (is_in_lista) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    }

    return 0;
}
