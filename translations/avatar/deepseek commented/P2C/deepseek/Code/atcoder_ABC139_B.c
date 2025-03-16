#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int hole = 1;
    int i = 0;
    int check = 1; // Using 1 for True and 0 for False

    while (check) {
        if (hole >= b) {
            check = 0; // Set check to 0 to exit the loop
        } else {
            hole = a * (i + 1) - i;
            i++;
        }
    }
    printf("%d\n", i);
    return 0;
}
