#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int* str2List(char* str) {
    int* ret = (int*)malloc(MAX_SIZE * sizeof(int));
    char* token = strtok(str, " ");
    int key = 0;
    while (token != NULL) {
        ret[key] = atoi(token);
        token = strtok(NULL, " ");
        key++;
    }
    return ret;
}

int main() {
    int n;
    char vStr[MAX_SIZE], cStr[MAX_SIZE];
    scanf("%d", &n);
    getchar(); // consume newline after integer input
    fgets(vStr, MAX_SIZE, stdin);
    fgets(cStr, MAX_SIZE, stdin);

    int* vList = str2List(vStr);
    int* cList = str2List(cStr);

    int max = 0;
    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }
    printf("%d\n", max);

    free(vList);
    free(cList);
    return 0;
}
