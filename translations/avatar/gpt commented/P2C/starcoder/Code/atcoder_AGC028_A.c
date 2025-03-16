#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, j, counter, Flag, Kaburi_Size;
    int *Number_i, *Number_j, *Number_iMN, *Kaburi_i, *Kaburi_j;
    char S[100000], T[100000];

    scanf("%d %d", &N, &M);
    scanf("%s", S);
    scanf("%s", T);

    Number_i = (int *)malloc(N * sizeof(int));
    Number_j = (int *)malloc(M * sizeof(int));
    Number_iMN = (int *)malloc(N * sizeof(int));
    Kaburi_i = (int *)malloc(N * sizeof(int));
    Kaburi_j = (int *)malloc(M * sizeof(int));

    for (i = 0; i < N; i++)
    {
        Number_i[i] = i;
    }

    for (j = 0; j < M; j++)
    {
        Number_j[j] = j;
    }

    for (i = 0; i < N; i++)
    {
        Number_iMN[i] = (int)(i * M / N);
    }

    for (j = 0; j < M; j++)
    {
        if (Number_j[j] == Number_iMN[j])
        {
            Kaburi_j[j] = Number_j[j];
        }
    }

    Kaburi_Size = sizeof(Kaburi_j) / sizeof(Kaburi_j[0]);

    for (counter = 0; counter < Kaburi_Size; counter++)
    {
        if (S[Kaburi_i[counter]] == T[Kaburi_j[counter]])
        {
            continue;
        }
        else
        {
            Flag = 1;
            break;
        }
    }

    if (Flag == 1)
    {
        printf("-1");
    }
    else
    {
        printf("%d", N * M / gcd(N, M));
    }

    return 0;
}

