#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int inp, i;
    int *lista;
    scanf("%d", &inp);
    lista = (int *) malloc(inp * sizeof(int));
    for(i = 0; i < inp; i++)
        scanf("%d", &lista[i]);
    for(i = 0; i < inp - 1; i++)
        printf("%d ", lista[i+1] - lista[i]);
    printf("%d\n", lista[inp-1] - lista[0]);
    for(i = inp - 1; i > 0; i--)
        printf("%d ", lista[i] - lista[i-1]);
    printf("%d\n", lista[inp-1] - lista[inp-1]);
    return 0;
}
