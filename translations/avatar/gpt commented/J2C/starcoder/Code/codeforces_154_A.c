#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[100000];
    int N, K, res, a, b;
    scanf("%d", &K);
    scanf("%s", arr);
    N = strlen(arr);
    res = 0;
    for (int k = 0; k < K; k++)
    {
        char input[100000];
        scanf("%s", input);
        a = 0;
        b = 0;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] == input[0])
                a++;
            else if (arr[i] == input[1])
                b++;
            else
            {
                res += (a < b)? a : b;
                a = b = 0;
            }
        }
        res += (a < b)? a : b;
    }
    printf("%d\n", res);
    return 0;
}

