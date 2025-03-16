#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    char buffer[100];

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d %d", &a, &b);

    c = a - b * 2;
    if (c < 0) c = 0;

    printf("%d\n", c);

    return 0;
}
