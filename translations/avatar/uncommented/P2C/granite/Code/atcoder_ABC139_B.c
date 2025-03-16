
#include <stdio.h>

int main() {
    int a, b, hole = 1, i = 0, check = 1;
    scanf("%d %d", &a, &b);
    while (check) {
        if (hole >= b) {
            check = 0;
        } else {
            hole = a * (i + 1) - i;
            i++;
        }
    }
    printf("%d", i);
    return 0;
}
//END-OF-CODE