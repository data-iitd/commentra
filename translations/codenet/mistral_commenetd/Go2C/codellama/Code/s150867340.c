
#include <stdio.h>

int main()
{
    int a, b, product;
    scanf("%d %d", &a, &b);
    product = a * b;
    if (product % 2 == 0)
    {
        printf("Even\n");
    }
    else
    {
        printf("Odd\n");
    }
    return 0;
}

// End of code 