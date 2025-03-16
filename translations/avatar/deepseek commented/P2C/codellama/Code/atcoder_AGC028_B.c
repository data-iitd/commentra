
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define N 100000
#define M 1000000
#define Nsq 1000

int main()
{
    int i, j, n, Nsq, MOD, N, M, ans, temp, inv[N], fact[M][Nsq], A[N];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read the size of the array
    read = getline(&line, &len, stdin);
    N = atoi(line);

    // Read the array elements
    read = getline(&line, &len, stdin);
    for (i = 0; i < N; i++)
    {
        A[i] = atoi(strtok(line, " "));
    }

    // Initialize the factorial table
    for (i = 0; i < Nsq; i++)
    {
        for (j = 0; j < Nsq; j++)
        {
            fact[i][j] = 1;
        }
    }

    // Compute the factorial table
    for (n = 1; n < Nsq; n++)
    {
        for (i = 0; i < Nsq; i++)
        {
            fact[i][n] *= fact[i][n - 1];
            fact[i][n] %= MOD;
        }
    }

    // Compute the factorial table row-wise
    for (n = 1; n < Nsq; n++)
    {
        for (i = 0; i < Nsq; i++)
        {
            fact[n][i] *= fact[n - 1][Nsq - 1];
            fact[n][i] %= MOD;
        }
    }

    // Compute the inverse factorial values
    for (i = 0; i < N; i++)
    {
        inv[i] = pow(i + 1, MOD - 2, MOD);
    }

    // Compute the temporary value
    for (i = 0; i < N; i++)
    {
        temp = inv[i] + inv[N - 1 - i] - 1;
        temp %= MOD;
    }

    // Compute the final answer
    for (i = 0; i < N; i++)
    {
        ans += (A[i] * temp % MOD);
        ans %= MOD;
    }

    // Multiply the final answer with the factorial of N
    ans *= fact[N][Nsq - 1];
    ans %= MOD;

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

