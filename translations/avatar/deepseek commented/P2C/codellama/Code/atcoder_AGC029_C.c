
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, K, i, j, a, b, c, d, e, f, g, h, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *A, *B, *C, *D, *E, *F, *G, *H, *I, *J, *K, *L, *M, *N, *O, *P, *Q, *R, *S, *T, *U, *V, *W, *X, *Y, *Z;
    int *dp, *cut, *is_possible, *bis;

    // Taking input from the user and processing it to create a list of integers
    scanf("%d", &N);
    A = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    // Modifying the list A to include only elements where the previous element is greater than or equal to the current element
    A[0] = A[0];
    for (i = 1; i < N; i++)
    {
        if (A[i - 1] >= A[i])
        {
            A[i] = A[i - 1];
        }
    }

    // Storing the length of the modified list A in N
    N = N;

    // Function to cut a list of tuples based on a given index
    cut = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        if (i < 1)
        {
            cut[i] = 0;
        }
        else if (A[i - 1] < cut[i - 1])
        {
            cut[i] = cut[i - 1];
        }
        else
        {
            cut[i] = A[i - 1];
        }
    }

    // Function to check if a given value of K is possible by modifying the list dp
    dp = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        if (i == 0)
        {
            dp[i] = A[i];
        }
        else if (A[i] <= dp[i - 1])
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = A[i];
        }
    }
    is_possible = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        if (i == 0)
        {
            is_possible[i] = 0;
        }
        else if (dp[i] <= dp[i - 1])
        {
            is_possible[i] = 1;
        }
        else
        {
            is_possible[i] = 0;
        }
    }

    // Function to perform a binary search to find the maximum possible value of K
    bis = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        if (i == 0)
        {
            bis[i] = 0;
        }
        else if (is_possible[i] == 1)
        {
            bis[i] = bis[i - 1];
        }
        else
        {
            bis[i] = bis[i - 1] + 1;
        }
    }

    // Printing the result of the binary search
    printf("%d", bis[N - 1]);

    // Freeing the memory allocated to the variables
    free(A);
    free(B);
    free(C);
    free(D);
    free(E);
    free(F);
    free(G);
    free(H);
    free(I);
    free(J);
    free(K);
    free(L);
    free(M);
    free(N);
    free(O);
    free(P);
    free(Q);
    free(R);
    free(S);
    free(T);
    free(U);
    free(V);
    free(W);
    free(X);
    free(Y);
    free(Z);
    free(dp);
    free(cut);
    free(is_possible);
    free(bis);

    return 0;
}

