
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *l = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &l[i]);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            for (k = j + 1; k < n; k++)
            {
                if (l[i] + l[j] == l[k])
                {
                    printf("YES");
                    return 0;
                }
            }
        }
    }
    printf("NO");
    return 0;
}

