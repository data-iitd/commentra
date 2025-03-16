
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, r = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        r ^= a[i];
    printf("The XOR result is: ");
    for (i = 0; i < n; i++)
        printf("%d ", r ^ a[i]);
    printf("\n");
    return 0;
}
