#include <stdio.h>

int main() {
    int a, b, sum = 0;
    
    scanf("%d", &a);
    scanf("%d", &b);
    
    for (int i = 0; i < 2; i++) {
        if (a >= b) {
            sum += a;
            a = a - 1;
        } else {
            sum += b;
            b = b - 1;
        }
    }
    
    printf("%d\n", sum);
    return 0;
}

// <END-OF-CODE>
