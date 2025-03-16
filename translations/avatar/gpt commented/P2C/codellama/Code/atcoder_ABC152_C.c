
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, a = 1, pos = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    int n[N];
    printf("Enter the elements separated by spaces: ");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &n[i]);
    }
    for (i = 1; i < N; i++)
    {
        if (n[pos] > n[i])
        {
            a += 1;
            pos = i;
        }
    }
    printf("%d", a);
    return 0;
}
