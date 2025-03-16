#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int R;
    scanf("%d", &R);
<<<<<<< HEAD
    if (R < 1200) {
        printf("ABC\n");
    } else if (R >= 2800) {
        printf("AGC\n");
    } else {
        printf("ARC\n");
    }
=======
    if (R < 1200) printf("ABC\n");
    else if (R >= 2800) printf("AGC\n");
    else printf("ARC\n");
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
