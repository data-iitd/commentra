#include <stdio.h>

<<<<<<< HEAD
void binPrint(int x, int bits) {
=======
void binPrint(unsigned int x, int bits) {
>>>>>>> 98c87cb78a (data updated)
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (x & (1 << i)) ? 1 : 0);
    }
    printf("\n");
}

int main(void) {
    unsigned int a, b;
    scanf("%u %u", &a, &b);

    binPrint(a & b, 32);
    binPrint(a | b, 32);
    binPrint(a ^ b, 32);
    
    return 0;
}

// <END-OF-CODE>
