
#include <stdio.h>

int main() {
    int inp;
    scanf("%d", &inp);

    int lista[inp];
    for (int i = 0; i < inp; i++) {
        scanf("%d", &lista[i]);
    }

    for (int i = 0; i < inp; i++) {
        if (i == 0) {
            printf("%d %d\n", lista[i+1] - lista[i], lista[inp-1] - lista[i]);
            continue;
        }

        if (i == inp-1) {
            printf("%d %d\n", lista[inp-1] - lista[inp-2], lista[inp-1] - lista[0]);
            continue;
        }

        if (lista[i] - lista[i-1] > lista[i+1] - lista[i]) {
            printf("%d ", lista[i+1] - lista[i]);
        } else {
            printf("%d ", lista[i] - lista[i-1]);
            if (lista[inp-1] - lista[i] > lista[i] - lista[0]) {
                printf("%d\n", lista[inp-1] - lista[i]);
            } else {
                printf("%d\n", lista[i] - lista[0]);
            }
        }
    }

    return 0;
}
