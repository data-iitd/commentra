
#include <stdio.h>
#include <math.h>

int main() {
    int n, x = 1;
    scanf("%d", &n);
    while (log2(n) % 1!= 0) {
        x++;
        n -= pow(2, floor(log2(n)));
    }
    printf("%d", x);
    return 0;
}
//END-OF-CODE