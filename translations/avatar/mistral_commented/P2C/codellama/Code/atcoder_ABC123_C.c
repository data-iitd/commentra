#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Define a constant variable N, which is the input number
    int N;
    scanf("%d", &N);

    // Define a list A, which consists of five integers, each input as a separate line
    int A[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]);
    }

    // Calculate the minimum value in the list A
    int min_value = A[0];
    for (int i = 1; i < 5; i++)
    {
        if (A[i] < min_value)
        {
            min_value = A[i];
        }
    }

    // Calculate the ceiling value of N divided by the minimum value in the list A
    int ceiling_value = (int)ceil((double)N / min_value);

    // Add 4 to the ceiling value to get the final answer
    int final_answer = ceiling_value + 4;

    // Print the final answer
    printf("%d", final_answer);

    // End of code
    return 0;
}
