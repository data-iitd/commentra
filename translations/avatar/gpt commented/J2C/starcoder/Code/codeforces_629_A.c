#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, j, counter, fine;
    char **arr;

    scanf("%d", &num);
    arr = (char **)malloc(num * sizeof(char *));
    for (i = 0; i < num; i++) {
        arr[i] = (char *)malloc(num * sizeof(char));
    }
    for (i = 0; i < num; i++) {
        scanf("%s", arr[i]);
    }
    for (i = 0; i < num; i++) {
        counter = 0;
        for (j = 0; j < num; j++) {
            if (arr[j][i] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
    }
    for (i = 0; i < num; i++) {
        counter = 0;
        for (j = 0; j < num; j++) {
            if (arr[i][j] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
    }
    printf("%d\n", fine);
    return 0;
}

