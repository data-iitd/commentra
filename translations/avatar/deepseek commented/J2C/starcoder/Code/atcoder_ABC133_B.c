
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, D, i, j, dist, answer;
    scanf("%d %d", &N, &D);
    int **vectors = (int**)malloc(N * sizeof(int*));
    for (i = 0; i < N; i++)
    {
        vectors[i] = (int*)malloc(D * sizeof(int));
        for (j = 0; j < D; j++)
        {
            scanf("%d", &vectors[i][j]);
        }
    }
    answer = 0;
    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            dist = 0;
            for (int d = 0; d < D; d++)
            {
                int x = (vectors[i][d] - vectors[j][d]);
                dist += (x * x);
            }
            double sq = sqrt(dist);
            // Check if the distance is an integer and increment the answer if it is
            answer += (abs(sq - floor(sq)) < 0.001? 1 : 0);
        }
    }
    printf("%d\n", answer);
    return 0;
}

