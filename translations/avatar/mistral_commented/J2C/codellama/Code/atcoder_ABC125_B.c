
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int n;
    char *vStr;
    char *cStr;

    int vList[MAX_LENGTH];
    int cList[MAX_LENGTH];

    int max = 0;

    read = getline(&line, &len, stdin);
    n = atoi(line);

    read = getline(&line, &len, stdin);
    vStr = line;

    read = getline(&line, &len, stdin);
    cStr = line;

    int i = 0;
    char *token = strtok(vStr, " ");
    while (token != NULL) {
        vList[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }

    i = 0;
    token = strtok(cStr, " ");
    while (token != NULL) {
        cList[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }

    for (i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }

    printf("%d\n", max);

    return 0;
}

