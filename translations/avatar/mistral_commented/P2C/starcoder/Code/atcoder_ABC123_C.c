#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int A[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]);
    }
    int min_value = A[0];
    for (int i = 1; i < 5; i++)
    {
        if (A[i] < min_value)
        {
            min_value = A[i];
        }
    }
    int ceiling_value = (int)ceil(N / min_value);
    int final_answer = ceiling_value + 4;
    printf("%d", final_answer);
    return 0;
}
