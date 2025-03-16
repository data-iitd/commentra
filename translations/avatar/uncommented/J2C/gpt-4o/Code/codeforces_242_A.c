#include <stdio.h>

int main() {
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    
    int count = 0;
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            if (i <= j) continue;
            count++;
        }
    }
    
    printf("%d\n", count);
    
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            if (i <= j) continue;
            printf("%d %d\n", i, j);
        }
    }
    
    return 0;
}

// <END-OF-CODE>
