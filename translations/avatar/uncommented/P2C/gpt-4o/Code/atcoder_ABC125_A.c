#include <stdio.h>

int main() {
    int a, b, t;
    scanf("%d %d %d", &a, &b, &t);
    
    int cookie = 0;
    double time = a; // Use double to handle the 0.5 addition

    while (time <= t + 0.5) {
        cookie += b;
        time += a;
    }

    printf("%d\n", cookie);
    return 0;
}

// <END-OF-CODE>
