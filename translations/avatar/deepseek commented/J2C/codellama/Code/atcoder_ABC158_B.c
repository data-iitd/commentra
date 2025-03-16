
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long N, A, B, k;
    scanf("%ld", &N);
    scanf("%ld", &A);
    scanf("%ld", &B);
    k = 0;

    // Check if the values of N, A, and B are within the specified ranges
    if (1 <= N && N <= pow(10, 18) && 0 <= A && 0 <= B && 0 < A + B && A + B <= pow(10, 18))
    {
        // Calculate the number of complete cycles (k) of A and B that fit into N
        if (A + B <= N)
        {
            k = N / (A + B);
            if (N - k * (A + B) > A)
            {
                printf("%ld\n", A * k + (N - k * (A + B)) - (N - (k * (A + B) + A)));
            }
            else
            {
                printf("%ld\n", A * k + (N - k * (A + B)));
            }
        }
        // If the sum of A and B is greater than N and A is less than or equal to N
        else if (A + B > N && A <= N)
        {
            printf("%ld\n", A);
        }
        // If none of the above conditions are met, print N
        else
        {
            printf("%ld\n", N);
        }
    }
    return 0;
}

