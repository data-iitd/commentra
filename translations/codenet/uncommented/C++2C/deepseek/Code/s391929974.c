#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int sq[10000], fr[5000];
    int *com;
    int tmp;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 1; i < n; i++) sq[i] = (i * i) % n;

        // Allocate memory for com
        com = (int *)malloc((n - 1) * sizeof(int));
        int com_size = 0;

        for (int i = 1; i < n; i++) {
            int f = 1;
            for (int j = 0; j < com_size; j++) {
                if (com[j] == sq[i]) {
                    f = 0;
                    break;
                }
            }
            if (f) {
                com[com_size++] = sq[i];
            }
        }

        for (int i = 0; i <= (n - 1) / 2; i++) fr[i] = 0;

        for (int i = 0; i < com_size; i++) {
            for (int j = 0; j < com_size; j++) {
                if (i != j) {
                    tmp = com[i] - com[j];
                    if (tmp < 0) tmp += n;
                    if (tmp > (n - 1) / 2) tmp = n - tmp;
                    fr[tmp]++;
                }
            }
        }

        for (int i = 1; i <= (n - 1) / 2; i++) printf("%d\n", fr[i]);

        // Free allocated memory
        free(com);
    }

    return 0;
}
