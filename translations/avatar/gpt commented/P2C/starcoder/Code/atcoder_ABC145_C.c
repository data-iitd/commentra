#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    scanf("%d", &N);
    
    int *x = malloc(N * sizeof(int));
    int *y = malloc(N * sizeof(int));
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }
    
    int *indices = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        indices[i] = i;
    }
    
    int *permutations = malloc(N * sizeof(int));
    int *distances = malloc(N * sizeof(int));
    
    int total_distance = 0;
    int distance = 0;
    int count = 0;
    int total = 0;
    int result = 0;
    
    do
    {
        total_distance = 0;
        for (int i = 0; i < N - 1; i++)
        {
            f = indices[i];
            t = indices[i + 1];
            distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            total_distance += distance;
        }
        
        distances[count] = total_distance;
        count++;
    } while (next_permutation(indices, indices + N));
    
    for (int i = 0; i < N; i++)
    {
        total += distances[i];
    }
    
    result = total / N;
    
    printf("%d", result);
    
    return 0;
}

