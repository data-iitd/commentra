#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n, i, sum = 0;
    int *list;

    scanf("%d", &n);
    list = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &list[i]);
        sum += list[i] % 2;
    }
    if (sum == 1) {
        for (i = 0; i < n; i++) {
            if (list[i] % 2 == 1) {
                printf("%d", i + 1);
                break;
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            if (list[i] % 2 == 0) {
                printf("%d", i + 1);
                break;
            }
        }
    }
    printf("\n