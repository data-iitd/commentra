

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[100];
    char *token;
    char *numlist[2];
    int Sheep, Wolve;

    while (fgets(line, sizeof(line), stdin)) {
        token = strtok(line, " ");
        numlist[0] = token;
        numlist[1] = strtok(NULL, " ");
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
