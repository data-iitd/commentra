#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int hole = 1;
    int i = 0;
    int check = 1; // true

    while (check) {
        if (hole >= b) {
            check = 0; // false
        } else {
            hole = a * (i + 1) - i;
            i++;
        }
    }
    
    printf("%d\n", i);
    return 0;
}

// <END-OF-CODE>
