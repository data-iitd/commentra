#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    char *numlist[2];
    int Sheep, Wolve;

    while (fgets(input, sizeof(input), stdin) != NULL) {
        char *token = strtok(input, " ");
        int index = 0;
        while (token != NULL) {
            numlist[index++] = token;
            token = strtok(NULL, " ");
        }

        Sheep = atoi(numlist[0]);
        Wolve = atoi(numlist[1]);

        if (Wolve >= Sheep) {
            printf("unsafe\n");
        } else {
            printf("safe\n");
        }
    }

    return 0;
}

