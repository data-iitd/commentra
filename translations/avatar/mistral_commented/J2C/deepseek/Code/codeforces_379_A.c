#include <stdio.h>

int main() {
    int a, b, res;
    scanf("%d %d", &a, &b);
    
    res = a;
    
    while (a >= b) {
        res += (a / b);
        a = (a / b) + (a % b);
    }
    
    printf("%d\n", res);
    
    return 0;
}

