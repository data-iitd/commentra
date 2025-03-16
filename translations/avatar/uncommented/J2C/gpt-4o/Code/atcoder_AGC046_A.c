#include <stdio.h>

int main() {
    int x, count = 0, tmp;
    
    // Read input
    scanf("%d", &x);
    tmp = x;
    x = 0;

    while (x != 360) {
        x += tmp;
        if (x > 360) {
            x -= 360;
        }
        count++;
    }

    printf("%d\n", count);
    return 0;
}

/* <END-OF-CODE> */
