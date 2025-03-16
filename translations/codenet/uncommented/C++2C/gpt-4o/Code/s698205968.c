#include <stdio.h>

int main() {
    int m, f, r;
    while (scanf("%d %d %d", &m, &f, &r) == 3 && (m != -1 || f != -1 || r != -1)) {
        if (m == -1 || f == -1) {
            printf("F");
        } else if (m + f >= 80) {
            printf("A");
        } else if (m + f >= 65) {
            printf("B");
        } else if (m + f >= 50 || r >= 50) {
            printf("C");
        } else if (m + f >= 30) {
            printf("D");
        } else {
            printf("F");
        }
        printf("\n");
    }

    return 0;
}

// <END-OF-CODE>
