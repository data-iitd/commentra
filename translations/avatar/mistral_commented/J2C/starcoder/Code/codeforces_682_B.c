
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_SIZE 100000

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);

    int list[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    qsort(list, n, sizeof(int), compare);

    int c = 1;
    for (int i = 0; i < n; i++) {
        if (list[i] >= c) {
            c++;
        }
    }

    printf("%d\n", c);

    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

