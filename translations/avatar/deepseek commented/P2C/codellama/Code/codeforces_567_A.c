
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int inp, i, j, len, diff1, diff2;
    char *str, *token;

    scanf("%d", &inp);
    str = (char *)malloc(inp * sizeof(char));
    scanf("%s", str);

    token = strtok(str, " ");
    len = 0;
    while (token != NULL)
    {
        len++;
        token = strtok(NULL, " ");
    }

    int *lista = (int *)malloc(len * sizeof(int));
    token = strtok(str, " ");
    for (i = 0; i < len; i++)
    {
        lista[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    for (i = 0; i < len; i++)
    {
        if (i == 0)
        {
            diff1 = lista[i + 1] - lista[i];
            diff2 = lista[len - 1] - lista[i];
            printf("%d %d\n", diff1, diff2);
            continue;
        }
        else if (i == len - 1)
        {
            diff1 = lista[len - 1] - lista[len - 2];
            diff2 = lista[len - 1] - lista[0];
            printf("%d %d\n", diff1, diff2);
            continue;
        }
        else if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i])
        {
            diff1 = lista[i + 1] - lista[i];
        }
        else
        {
            diff1 = lista[i] - lista[i - 1];
        }
        if (lista[len - 1] - lista[i] > lista[i] - lista[0])
        {
            diff2 = lista[len - 1] - lista[i];
        }
        else
        {
            diff2 = lista[i] - lista[0];
        }
        printf("%d %d\n", diff1, diff2);
    }
    return 0;
}
