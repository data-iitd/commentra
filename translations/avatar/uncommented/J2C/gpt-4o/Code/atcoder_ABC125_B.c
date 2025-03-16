#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void str2List(char *str, int *arr) {
    char *token = strtok(str, " ");
    int index = 0;
    while (token != NULL) {
        arr[index++] = atoi(token);
        token = strtok(NULL, " ");
    }
}

int main() {
    int n;
    scanf("%d\n", &n);

    char vStr[MAX_SIZE];
    fgets(vStr, sizeof(vStr), stdin);
    
    char cStr[MAX_SIZE];
    fgets(cStr, sizeof(cStr), stdin);

    int vList[MAX_SIZE] = {0};
    int cList[MAX_SIZE] = {0};

    str2List(vStr, vList);
    str2List(cStr, cList);

    int max = 0;
    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }

    printf("%d\n", max);
    return 0;
}

// <END-OF-CODE>
