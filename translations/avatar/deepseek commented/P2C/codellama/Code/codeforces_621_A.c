
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum = 0, od = 0, ok = 0;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int *lst = (int *)malloc(n * sizeof(int));
    printf("Enter the list of integers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &lst[i]);
    for (i = 0; i < n; i++)
    {
        if (lst[i] % 2 == 0)
            sum += lst[i];
        else
        {
            if (ok || od > 1)
            {
                sum += lst[i];
                od--;
                ok = !ok;
            }
        }
    }
    printf("The sum of the list is: %d", sum);
    free(lst);
    return 0;
}

