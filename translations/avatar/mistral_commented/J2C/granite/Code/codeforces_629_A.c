
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num;
    scanf("%d", &num);

    char **arr = (char **)malloc(num * sizeof(char *));
    for (int i = 0; i < num; i++) {
        arr[i] = (char *)malloc(num * sizeof(char));
        scanf("%s", arr[i]);
    }

    int counter = 0;
    int fine = 0;

    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[i][k] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
        counter = 0;
    }

    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[k][i] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
        counter = 0;
    }

    printf("%d", fine);

    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
