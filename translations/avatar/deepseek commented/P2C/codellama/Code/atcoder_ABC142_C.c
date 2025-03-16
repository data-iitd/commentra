
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    char *str = (char *)malloc(N * 10);
    scanf("%s", str);

    int *arr = (int *)malloc(N * sizeof(int));
    char *token = strtok(str, " ");
    int i = 0;
    while (token != NULL)
    {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }

    int *arr_ = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        arr_[i] = i + 1;
    }

    int *arr__ = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        arr__[i] = arr_[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr__[i];
                arr__[i] = arr__[j];
                arr__[j] = temp;
            }
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        printf("%d ", arr__[i]);
    }
    printf("%d\n", arr__[N - 1]);

    free(str);
    free(arr);
    free(arr_);
    free(arr__);

    return 0;
}

