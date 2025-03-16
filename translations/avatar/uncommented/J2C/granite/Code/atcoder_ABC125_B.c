
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    char vStr[1000];
    char cStr[1000];
    int vList[1000];
    int cList[1000];
    int max = 0;

    scanf("%d", &n);
    scanf("%s", vStr);
    char *token = strtok(vStr, " ");
    int i = 0;
    while (token!= NULL) {
        vList[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    scanf("%s", cStr);
    token = strtok(cStr, " ");
    i = 0;
    while (token!= NULL) {
        cList[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    for (int i = 0; i < n; i++) {
        int profit = vList[i] - cList[i];
        if (profit > 0) {
            max += profit;
        }
    }

    printf("%d\n", max);

    return 0;
}

