#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
<<<<<<< HEAD
    return (a < b) ? b : a;
=======
    return (a > b) ? a : b;
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int A, B;
    
    // Read two integers from input
    scanf("%d %d", &A, &B);

    // Calculate the maximum of A+B, A-B, and A*B
    int mx = max(A + B, A - B);
    mx = max(mx, A * B);

    // Print the maximum value
    printf("%d\n", mx);

    return 0;
}

/* <END-OF-CODE> */
