#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int tap = 0;
    int consent = 1;
    
    while (consent < b) {
        consent += a - 1;
        tap++;
    }
    
    printf("%d\n", tap);
    return 0;
}

// <END-OF-CODE>
