
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100], i, n, j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            printf("The position of the element is %d", i + 1);
            break;
        }
    }
    return 0;
}

