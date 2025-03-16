
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    char vStr[100000];
    scanf("%s", vStr);
    int vList[n];
    for (int i = 0; i < n; i++) {
        vList[i] = vStr[i] - '0';
    }
    char cStr[100000];
    scanf("%s", cStr);
    int cList[n];
    for (int i = 0; i < n; i++) {
        cList[i] = cStr[i] - '0';
    }
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

