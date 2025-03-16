
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if ((a * b) % 2!= 0) {
        printf("Odd\n");
    } else {
        printf("Even\n");
    }
    return 0;
}
