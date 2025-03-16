
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char *arr;
    int N, K, a, b, res = 0;
    scanf("%d", &N);
    arr = (char *)malloc(N * sizeof(char));
    scanf("%s", arr);
    scanf("%d", &K);
    for (int k = 0; k < K; k++)
    {
        char *input;
        input = (char *)malloc(2 * sizeof(char));
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
                res += min(a, b);
                a = b = 0;
            }
        }
        res += min(a, b);
    }
    printf("%d", res);
    return 0;
}

