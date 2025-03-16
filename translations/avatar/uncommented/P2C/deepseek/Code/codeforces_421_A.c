#include <stdio.h>

int main() {
    int n, a, b;
    int lista[100], listb[100];
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < a; i++) {
        scanf("%d", &lista[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &listb[i]);
    }
    for (int k = 0; k < n; k++) {
        int isInLista = 0;
        for (int j = 0; j < a; j++) {
            if (k + 1 == lista[j]) {
                isInLista = 1;
                break;
            }
        }
        if (isInLista) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    }
    printf("\n");
    return 0;
}
