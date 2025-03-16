#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int sq[10000], fr[5000];
<<<<<<< HEAD
    int *com = NULL;
=======
    int *com = (int *)malloc(10000 * sizeof(int));
>>>>>>> 98c87cb78a (data updated)
    int com_size = 0;
    int tmp;

    while (1) {
        scanf("%d", &n);
        if (!n) break;

        for (int i = 1; i < n; i++) {
            sq[i] = (i * i) % n;
        }
<<<<<<< HEAD

        // Clear the com vector
        com_size = 0;
        com = (int *)malloc(n * sizeof(int));
=======
        com_size = 0;
>>>>>>> 98c87cb78a (data updated)

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

        for (int i = 0; i <= (n - 1) / 2; i++) {
            fr[i] = 0;
        }

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

        for (int i = 1; i <= (n - 1) / 2; i++) {
            printf("%d\n", fr[i]);
        }
<<<<<<< HEAD

        free(com); // Free the allocated memory for com
    }

=======
    }

    free(com);
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
