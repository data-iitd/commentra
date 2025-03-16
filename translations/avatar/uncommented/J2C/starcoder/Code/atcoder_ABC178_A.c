#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x;
    scanf("%d", &x);
    int result = (x == 1)? 1 : 0;
    printf("%d\n", result);
    return EXIT_SUCCESS;
}
