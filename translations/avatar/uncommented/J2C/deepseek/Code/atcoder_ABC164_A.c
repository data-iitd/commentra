#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char *numlist[2];
    int Sheep, Wolve;

    while (1) {
        if (fgets(input, sizeof(input), stdin) != NULL) {
            numlist[0] = strtok(input, " ");
            numlist[1] = strtok(NULL, " ");
            if (numlist[0] == NULL || numlist[1] == NULL) {
                break;
            }
            Sheep = atoi(numlist[0]);
            Wolve = atoi(numlist[1]);
            if (Wolve >= Sheep) {
                printf("unsafe\n");
            } else {
                printf("safe\n");
            }
        } else {
            break;
        }
    }
    return 0;
}
