
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read initial values for r, D, and x
    int r, D, x;
    scanf("%d %d %d", &r, &D, &x);
    
    // Loop to calculate and print the values of x for 10 iterations
    for (int i = 1; i <= 10; i++) {
        x = r*x - D;
        printf("%d\n", x);
    }
    
    return 0;
}
