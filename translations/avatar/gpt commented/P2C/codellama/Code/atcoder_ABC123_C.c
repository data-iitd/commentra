#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    int A[5];
    int i;
    int min;

    // Read an integer input from the user
    scanf("%d", &N);

    // Read 5 integer inputs from the user and store them in a list A
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]);
    }

    // Calculate the minimum value from the list A, divide N by this minimum value,
    // take the ceiling of the result, and add 4 to it before printing the final result
    min = A[0];
    for (i = 1; i < 5; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    printf("%d\n", (int)ceil((double)N / min) + 4);

    return 0;
}

