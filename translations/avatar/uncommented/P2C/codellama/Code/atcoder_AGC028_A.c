
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N, M;
    char S[100000], T[100000];
    int list_S[100000], list_T[100000];
    int Number_i[100000], Number_iMN[100000];
    int Number_j[100000], Kaburi_j[100000];
    int Kaburi_i[100000], counter, Flag, Kaburi_Size;
    int i, j, a, b;

    scanf("%d %d", &N, &M);
    scanf("%s", S);
    scanf("%s", T);

    for (i = 0; i < N; i++)
    {
        list_S[i] = S[i];
    }

    for (i = 0; i < M; i++)
    {
        list_T[i] = T[i];
    }

    for (i = 0; i < N; i++)
    {
        Number_i[i] = i;
    }

    for (i = 0; i < N; i++)
    {
        Number_iMN[i] = i * M / N;
    }

    for (i = 0; i < M; i++)
    {
        Number_j[i] = i;
    }

    for (i = 0; i < M; i++)
    {
        Kaburi_j[i] = Number_j[i];
    }

    for (i = 0; i < N; i++)
    {
        Kaburi_i[i] = Number_i[i];
    }

    counter = 0;
    Flag = 0;
    Kaburi_Size = M;

    while (counter <= Kaburi_Size - 1)
    {
        if (list_S[Kaburi_i[counter]] == list_T[Kaburi_j[counter]])
        {
            counter++;
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
        a = N;
        b = M;
        printf("%d", (int)(a * b / gcd(a, b)));
    }

    return 0;
}

