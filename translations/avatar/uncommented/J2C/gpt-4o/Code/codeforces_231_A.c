#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int count = 0;

    while (t-- > 0) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
            count++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}

// <END-OF-CODE>
