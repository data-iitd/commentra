#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    int ABC[3] = {A, B, C};
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (ABC[i] == 5)
        {
            count++;
        }
    }
    if (count == 2 && A + B + C == 17)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}

