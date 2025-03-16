#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);  // Take input from user

    // Check if the numbers contain exactly two 5s
    if ((a == 5 && b == 5 && a + b + c == 17) ||
        (a == 5 && c == 5 && a + b + c == 17) ||
        (b == 5 && c == 5 && a + b + c == 17)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
