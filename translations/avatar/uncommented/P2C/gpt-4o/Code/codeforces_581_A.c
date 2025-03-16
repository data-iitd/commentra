#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int min_val = (a < b) ? a : b;
    int max_val = (a > b) ? a : b;
    int difference = (max_val - min_val) / 2;

    printf("%d %d\n", min_val, difference);
    
    return 0;
}
// <END-OF-CODE>
