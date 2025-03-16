#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d", (a < b)? a : b, (a > b)? a : b);
    return EXIT_SUCCESS;
}
