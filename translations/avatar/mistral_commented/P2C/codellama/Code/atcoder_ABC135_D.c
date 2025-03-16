########
# Code #
########

# Include necessary libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Define the modulus value
#define mod 1000000007

// Function to read an integer
int I()
{
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers
int *III()
{
    int *arr = (int *)malloc(sizeof(int) * I());
    for (int i = 0; i < I(); i++)
        arr[i] = I();
    return arr;
}

// Function to read a list of lists (2D array)
int **Line(int N)
{
    int **arr = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * I());
        for (int j = 0; j < I(); j++)
            arr[i][j] = I();
    }
    return arr;
}

// Function to read a string
char *str()
{
    char *s = (char *)malloc(sizeof(char) * I());
    scanf("%s", s);
    return s;
}

// Function to read a character
char C()
{
    char c;
    scanf(" %c", &c);
    return c;
}

// Function to print an integer
void print(int x)
{
    printf("%d\n", x);
}

// Function to print a string
void print(char *s)
{
    printf("%s\n", s);
}

// Function to print a character
void print(char c)
{
    printf("%c\n", c);
}

// Function to print a list of integers
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to print a list of lists (2D array)
void print(int **arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < I(); j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

// Function to print a list of strings
void print(char **arr, int N)
{
    for (int i = 0; i < N; i++)
        printf("%s\n", arr[i]);
}

// Function to print a list of characters
void print(char *arr, int N)
{
    for (int i = 0; i < N; i++)
        printf("%c\n", arr[i]);
}

// Function to print a list of pairs
void print(int *arr, int N)
{
    for (int i = 0; i < N; i++)
        printf("%d %d\n", arr[i], arr[i + 1]);
}

// Function to print a list of pairs
void print(char *arr, int N)
{
    for (int i = 0; i < N; i++)
        printf("%c %c\n", arr[i], arr[i + 1]);
}

// Function to print a list of triples
void print(int *arr, int N)
{
    for (int i = 0; i < N; i++)
        printf("%d %d %d\n", arr[i], arr[i + 1], arr[i + 2]);
}

// Function to print a list of triples
void print(char *arr, int N)
{
    for (int i = 0; i < N; i++)
        printf("%c %c %c\n", arr[i], arr[i + 1], arr[i + 2]);
}

// Function to print a list of lists (2D array)
void print(int **arr, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(char **arr, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%c ", arr[i][j]);
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(char ***arr, int N, int M, int L)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
                printf("%c ", arr[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(int ***arr, int N, int M, int L)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
                printf("%d ", arr[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(char ****arr, int N, int M, int L, int K)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
            {
                for (int l = 0; l < K; l++)
                    printf("%c ", arr[i][j][k][l]);
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(int ****arr, int N, int M, int L, int K)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
            {
                for (int l = 0; l < K; l++)
                    printf("%d ", arr[i][j][k][l]);
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(char *****arr, int N, int M, int L, int K, int P)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
            {
                for (int l = 0; l < K; l++)
                {
                    for (int m = 0; m < P; m++)
                        printf("%c ", arr[i][j][k][l][m]);
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(int *****arr, int N, int M, int L, int K, int P)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
            {
                for (int l = 0; l < K; l++)
                {
                    for (int m = 0; m < P; m++)
                        printf("%d ", arr[i][j][k][l][m]);
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(char ******arr, int N, int M, int L, int K, int P, int Q)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
            {
                for (int l = 0; l < K; l++)
                {
                    for (int m = 0; m < P; m++)
                    {
                        for (int n = 0; n < Q; n++)
                            printf("%c ", arr[i][j][k][l][m][n]);
                        printf("\n");
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(int ******arr, int N, int M, int L, int K, int P, int Q)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
            {
                for (int l = 0; l < K; l++)
                {
                    for (int m = 0; m < P; m++)
                    {
                        for (int n = 0; n < Q; n++)
                            printf("%d ", arr[i][j][k][l][m][n]);
                        printf("\n");
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(char *******arr, int N, int M, int L, int K, int P, int Q, int R)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
            {
                for (int l = 0; l < K; l++)
                {
                    for (int m = 0; m < P; m++)
                    {
                        for (int n = 0; n < Q; n++)
                        {
                            for (int o = 0; o < R; o++)
                                printf("%c ", arr[i][j][k][l][m][n][o]);
                            printf("\n");
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(int *******arr, int N, int M, int L, int K, int P, int Q, int R)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
            {
                for (int l = 0; l < K; l++)
                {
                    for (int m = 0; m < P; m++)
                    {
                        for (int n = 0; n < Q; n++)
                        {
                            for (int o = 0; o < R; o++)
                                printf("%d ", arr[i][j][k][l][m][n][o]);
                            printf("\n");
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Function to print a list of lists (2D array)
void print(char ********arr, int N, int M, int L, int K, int P, int Q, int R, int S)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < L; k++)
            {
                for (int l = 0; l < K; l++)
                {
                    for (int m = 0; m < P; m++)
                    {
                        for (int n = 0; n < Q; n++)
                        {
                            for (int o = 0; o < R; o++)
                            {
                                for (int p = 0; p < S; p++)
                                    printf("%c ", arr[i][j][k][l][m][n][o][p]);
                                printf("\n");
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
}
