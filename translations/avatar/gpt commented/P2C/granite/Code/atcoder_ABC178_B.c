
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read four integers from input
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Calculate the maximum value from the products of the pairs and return it
    int ans = fmax(fmax(a * c, b * d), fmax(a * d, b * c));
    printf("%d\n", ans);
    
    return 0;
}
// END-OF-CODE