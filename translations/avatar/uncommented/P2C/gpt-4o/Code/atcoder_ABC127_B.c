#include <stdio.h>
#include <math.h>

int main() {
    int r, D, x;
    scanf("%d %d %d", &r, &D, &x);
    
    for (int i = 2; i < 12; i++) {
        int result = (int)((pow(r, i - 1) * (x + (double)D / (1 - r))) - (double)D / (1 - r));
        printf("%d\n", result);
    }
    
    return 0;
}

// <END-OF-CODE>
