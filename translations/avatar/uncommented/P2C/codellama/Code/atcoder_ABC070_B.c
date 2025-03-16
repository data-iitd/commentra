
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int A[4];
    int i;
    char *str;
    char *token;
    char *delim = " ";

    str = (char *)malloc(100 * sizeof(char));
    scanf("%s", str);

    token = strtok(str, delim);
    i = 0;
    while (token != NULL)
    {
        A[i] = atoi(token);
        token = strtok(NULL, delim);
        i++;
    }

    if (A[1] <= A[2] || A[3] <= A[0])
    {
        printf("0");
    }
    else
    {
        qsort(A, 4, sizeof(int), compare);
        printf("%d", A[2] - A[1]);
    }

    free(str);
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

