#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num;
    scanf("%d", &num);
    
    char **arr = (char **)malloc(num * sizeof(char *));
    for (int i = 0; i < num; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char)); // Assuming max length of each string is 100
        scanf("%s", arr[i]);
    }

    int fine = 0;

    // Count 'C's in columns
    for (int i = 0; i < num; i++) {
        int counter = 0;
        for (int k = 0; k < num; k++) {
            if (arr[k][i] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
    }

    // Count 'C's in rows
    for (int i = 0; i < num; i++) {
        int counter = 0;
        for (int k = 0; k < num; k++) {
            if (arr[i][k] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2;
    }

    printf("%d\n", fine);

    // Free allocated memory
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

// <END-OF-CODE>
