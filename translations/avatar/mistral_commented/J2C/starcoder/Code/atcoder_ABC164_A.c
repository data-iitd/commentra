#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char **scList = (char **)malloc(sizeof(char *));
    int Sheep, Wolve;
    scanf("%d %d", &Sheep, &Wolve);
    for (int i = 0; i >= 0; i++) {
        char *line = (char *)malloc(sizeof(char) * 1000);
        scanf("%s", line);
        scList[i] = line;
    }
    char *numlist[2];
    numlist[0] = strchr(scList[0],'');
    numlist[1] = strchr(numlist[0] + 1,'');
    Sheep = atoi(numlist[0] + 1);
    Wolve = atoi(numlist[1]);
    if (Wolve >= Sheep) {
        printf("unsafe");
    } else {
        printf("safe");
    }
    return 0;
}

