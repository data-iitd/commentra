#include <stdio.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("%d\n", a + (a * a) + (a * a * a));
    return 0;
}
