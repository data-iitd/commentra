#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    int key;
    int value;
} Pair;

Pair* str2List(char* str) {
    char* token = strtok(str, " ");
    int count = 0;
    Pair* ret = (Pair*)malloc(MAX_LINE_LENGTH * sizeof(Pair));

    while (token != NULL) {
        ret[count].key = count;
        ret[count].value = atoi(token);
        token = strtok(NULL, " ");
        count++;
    }

    return ret;
}

int main() {
    char nStr[MAX_LINE_LENGTH], vStr[MAX_LINE_LENGTH], cStr[MAX_LINE_LENGTH];
    Pair* vList;
    Pair* cList;
    int n, max = 0;

    fgets(nStr, MAX_LINE_LENGTH, stdin);
    fgets(vStr, MAX_LINE_LENGTH, stdin);
    fgets(cStr, MAX_LINE_LENGTH, stdin);

    n = atoi(nStr);
    vList = str2List(vStr);
    cList = str2List(cStr);

    for (int i = 0; i < n; i++) {
        int profit = vList[i].value - cList[i].value;
        if (profit > 0) {
            max += profit;
        }
    }

    printf("%d\n", max);

    free(vList);
    free(cList);

    return 0;
}

