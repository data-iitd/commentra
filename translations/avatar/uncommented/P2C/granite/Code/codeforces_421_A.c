
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
    for (int i = 1; i <= n; i++) {
        int found = 0;
        for (int j = 0; j < a; j++) {
            if (i == lista[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    }
    printf("\n");
    return 0;
}
