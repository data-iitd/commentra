#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int N;
    double x[100000];
    char u[100000];
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lf", &x[i]);
        scanf("%s", u[i]);
    }
    printf("%.2lf", solve(x, u, N));
    return 0;
}

double solve(double x[], char u[], int N)
{
    double sum = 0;
    for(int i = 0; i < N; i++)
    {
        if(strcmp(u[i], "JPY") == 0)
            sum += x[i];
        else
            sum += x[i] * 380000;
    }
    return sum;
}

