
#include <stdio.h>

int main() {
    int n, a, b, k;
    scanf("%d %d %d", &n, &a, &b);

    int lista[a], listb[b];
    for (int i = 0; i < a; i++) {
        scanf("%d", &lista[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &listb[i]);
    }

    for (k = 1; k <= n; k++) {
        int flag = 0;
        for (int i = 0; i < a; i++) {
            if (k == lista[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    }
    printf("\n");
    return 0;
}
