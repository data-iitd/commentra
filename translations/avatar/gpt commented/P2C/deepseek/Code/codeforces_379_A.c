#include <stdio.h>

int main() {
    int candeleIntere, b;
    scanf("%d %d", &candeleIntere, &b);

    int s = 0;
    int restoSciolte = 0;

    while (candeleIntere > 0 || restoSciolte >= b) {
        s += candeleIntere;
        restoSciolte += candeleIntere % b;
        candeleIntere /= b;

        if (restoSciolte >= b) {
            candeleIntere += restoSciolte / b;
            restoSciolte %= b;
        }
    }

    printf("%d\n", s);
    return 0;
}
